/*===========================================================================*/
/*                                                                           */ 
/* This program demonstrates basic operations on a STATISTICA data file.     */
/* It will read a raw data file, print its basic characteristics             */
/* (including alphanumeric values for the second variable in the data file), */
/* and then create a new STATISTICA data file with one additional variable.  */
/* That variable will contain the sum of all variables in the input file.    */
/* Arguments (input file name, output file name) are passed by command line  */
/* (from DOS) in the following manner:                                        */
/*                                                                           */
/*                       demo input output                                   */
/*                                                                           */
/* This program was developed using a standard subset of the C language, and */
/* it is ANSI compatible.                                                    */
/* Enclosed demo.exe was created with Microsoft C 7.00 using command         */
/*   cl demo.c                                                               */
/*===========================================================================*/


#include   <stdio.h>
#include   <stdlib.h>

#include "demo.h"

FILE   *in,   /* input stream */
       *out;  /* output stream */

struct   HeadTag   InHeader,   /* header of input file */
                  OutHeader;   /* header of output file */
struct   InfoTag   InArray,    /* information array about input file */
                  OutArray;    /* information array about output file */

main(argc,argv)
int argc;
char * argv[];
{ 
   /*-- get arguments from command line --*/
   if ( argc <= 2 ) {
      printf("\n To use the program, enter: \ndemo inp_file out_file\n");
      exit(1);
   }
   in = fopen( argv[1], "rb");
   if ( in == NULL ){
      printf("\n Cannot open input file.\n");
      exit(1);
   }

   /*-- initializing data structures for the input file --*/
   InitInputFile();

   /*-- printing some information about the input file --*/
   PrintInputInfo();

   /*-- creating second (output) file --*/
   out = fopen( argv[2], "wb");
   if ( in == NULL ){
      printf("\n Cannot create output file.\n");
      exit(1);
   }

   /*-- creating information header for output file; writing it to disk --*/
   CreateOutputHeader();

   /*-- processing data for output file --*/
   ProcessData();

   /*-- closing files and exiting --*/
   fclose(in);
   fclose(out);
   printf("\nNormal program termination.\n");
   exit(0);
}
 
/*------------------------------- end of main ----------------------------------*/

void   InitInputFile(void)
/*-- read from disk basic information about input file and store it in
   InHeader and InArray structures --*/
{
   fread( &InHeader, SizeFH, 1, in);
   if ( memcmp( InHeader.Title, "CSS ", 4 ) ||
        (InHeader.Code != CSS_CODE &&
         InHeader.Code != CSSW_CODE &&
         InHeader.Code != CSS_CODE_EX &&
         InHeader.Code != CSSW5_CODE) ) {
      printf(" This is not a STATISTICA data file.");
      exit(1);
   }
   if ( InHeader.NV <= 1 ) {
      printf(" The input file for this program must contain at least two variables.");
      exit(1);
   }
   if ( InHeader.NV >= MAX_CSS_VARS ) {
      printf(" Number of variables must not exceed %d. ", MAX_CSS_VARS);
      exit(1);
   }
   switch ((int) InHeader.NArr ){
      case 5 :
         InHeader.SL1Len = 0;
         InHeader.SL2Len = 0;
      case 7 :
         InHeader.SL3Len = 0;
   }
   fseek( in, 24 + InHeader.NArr * 2, SEEK_SET);
   fread( &InArray, SizeFI, 1, in);
}

/*------------------------------- end of InitInputFile -------------------------*/

void   PrintInputInfo(void)
{
   char Name[8];
   union ValueTag MD;
   long Offset;
   struct FmTag Format;
   int NbAlpha,NbRead,i;
   long OffsAlpha;
   struct LabTag Alpha[10];

   printf("\nInput file characteristics:\n Variables: %ld\n Cases: %ld\n Precision: %ldB\n",
          InHeader.NV,InHeader.NC,InHeader.Prec);
   if ( InHeader.Code != CSS_CODE )
      printf("\n This is a STATISTICA/W data file\n");
   /*-- now print specifications for the second variable --*/
   Offset = 24L + 2 * InHeader.NArr + InHeader.NCLen + InHeader.HLen;
   /*-- find name --*/
   fseek( in, Offset + 8, SEEK_SET);
   fread( Name, 8, 1, in);
   Offset += InHeader.VLen;
   fseek( in, Offset + 2, SEEK_SET);
   fread( &Format, 2, 1,in);
   Offset += InHeader.FLen;
   fseek( in, Offset + InHeader.Prec, SEEK_SET);
   fread( &MD, (int)InHeader.Prec, 1, in);
   printf("\nSpecifications for second variable:\n");
   printf(" Name: %.8s\n",Name);
   if ( InHeader.Prec == 4 )
      printf(" MD Code: %f\n",MD.f);
   else
      printf(" MD Code: %lf\n",MD.d);
   printf(" Format: width = %d, decimal = %d\n",(int)Format.Nz,(int)Format.Nd);
   if ( InHeader.NArr >= 7 ){
      /*-- if alphanumeric value labels exist, find out how many--*/
      Offset += InHeader.MDLen;
      fseek( in, Offset + 2, SEEK_SET);
      fread( &NbAlpha, 2, 1, in);
      if ( NbAlpha ){
         /*-- find where they begin --*/
         Offset += InHeader.SL1Len;
         fseek( in, Offset + 4, SEEK_SET);
         fread( &OffsAlpha, 4, 1, in);
         Offset += InHeader.SL2Len;
         /*-- here the offsets to long value labels begin --*/
         Offset += InHeader.SL3Len;
         /*-- here the long variable names begin --*/
         Offset += InArray.MemVar;
         /*-- here alphanumerics starts --*/
         fseek( in, Offset + OffsAlpha, SEEK_SET);
         /*-- read first 10 alphanumeric specification --*/
         fread( Alpha, SizeLT, NbRead = min( NbAlpha, 10), in);
         printf(" Number of alphanumerics: %d\n",NbAlpha);
         for ( i = 0 ; i < NbRead; i++ )
            printf(" Alpha: %.8s Value: %f\n",Alpha[i].T,Alpha[i].V);
      }
      else
         printf(" No text value labels for the second variable in the file.\n");
   }
   else
      printf(" There are no text value labels in this file.\n");
}

/*------------------------------- end of PrintInputInfo ------------------------*/

void   CreateOutputHeader(void)
/*-create output file header, make changes to accomodate additional variable-*/
{
   union ValueTag MD;
   int NbAlpha;
   long OffsAlpha,OffsLongAlpha;

   /* we are going to create the same type of data file as the input:
   /*-- copy basic information --*/
   memcpy( &OutHeader, &InHeader, SizeFH );
   OutHeader.NV++;
   OutHeader.VLen += 8;
   OutHeader.FLen += 2;
   OutHeader.MDLen += OutHeader.Prec;
   if ( OutHeader.SL1Len )
      OutHeader.SL1Len += 2;
   if ( OutHeader.SL2Len )
      OutHeader.SL2Len += 4;
   if ( OutHeader.SL3Len )
      OutHeader.SL3Len += 4;
   fwrite( &OutHeader, (unsigned int)(24 + OutHeader.NArr * 2), 1, out);

   /*-- copy information array --*/
   memcpy( &OutArray, &InArray, SizeFI );
   if ( OutHeader.Code == CSS_CODE )
      OutArray.ExtraInfo = 0;
   // all other formats should have ExtraInfo set correctly;
   fwrite( &OutArray, SizeFI, 1, out);

   /*-- copy text header --*/
   fseek( in, 24 + OutHeader.NArr * 2 + SizeFI, SEEK_SET );
   fcopy( out, in, 80);

   /*-- variable names --*/
   fwrite( "     SUM", 8, 1, out);
   fcopy( out, in, InHeader.VLen);

   /*-- variable formats --*/
   fwrite( "", 2, 1, out); /*-- create default 8.3 --*/
   fcopy( out, in, InHeader.FLen);

   /*-- MD codes --*/
   if ( InHeader.Prec == 4 )
      MD.f = (float)-9999.0;
   else
      MD.d = -9999.0;
   fwrite( &MD, (int)InHeader.Prec, 1, out);
   fcopy( out, in, InHeader.MDLen );

   /*-- number of alphanumeric value labels --*/
   if ( InHeader.SL1Len ){
      NbAlpha = 0;
      fwrite( &NbAlpha, 2, 1, out);
      fcopy( out, in, InHeader.SL1Len );
   }

   /*-- offset to alphanumeric value labels --*/
   if ( InHeader.SL2Len ){
      OffsAlpha = 0L;
      fwrite( &OffsAlpha, 4, 1, out);
      fcopy( out, in, InHeader.SL2Len );
   }

   /*-- offset to long alphanumeric value labels --*/
   if ( InHeader.SL3Len ){
      OffsLongAlpha = 0L;
      fwrite( &OffsLongAlpha, 4, 1, out);
      fcopy( out, in, InHeader.SL3Len );
   }

   /*-- long variable names (labels/formulas) --*/
   fcopy( out, in, (unsigned int)OutArray.MemVar);

   /*-- short alphanumeric values for all variables;
      NOTE: make sure that third argument in fcopy is not larger than
      the max unsigned integer value; otherwise write your own fcopy routine --*/
   fcopy( out, in, (unsigned int)OutArray.MemSvl);

   /*-- long alphanumerics - see NOTE above --*/
   fcopy( out, in, (unsigned int)OutArray.MemLvl);

   /*-- copy extra info if applicable: --*/
   fcopy( out, in, (unsigned int)OutArray.ExtraInfo);
}

/*----------------------------- end of CreateOutputHeader ----------------------*/

void   ProcessData(void)
/*-- copy data, process each case and compute the sum of variables;
   we assume that the file pointers are at the end of header specifications 
   and at the bginning of the data for both files --*/
{
   double * pD,sumD;
   float * pF,sumF;
   long Offset,i;
   int RecordLen,j;
   BYTE * pData;
   char CaseName[20];

   /*-- first move pointers to the nearest multiply of 512B --*/
   /* get offset on input file */
   Offset = ftell( in );
   Ceil512( &Offset );
   fseek( in, Offset, SEEK_SET );
   /* get offset on output file */
   Offset = ftell( out );
   Ceil512( &Offset );
   fseek( out, Offset, SEEK_SET );

   /*-- next, allocate memory for one record of data --*/
   if ( (pData = malloc( (unsigned int)(InHeader.Prec*InHeader.NV) )) == NULL ){
      printf("\n Memory allocation error.");
      exit(1);
   }

   /*-- process data --*/
   for ( i = 0, RecordLen = (int)(InHeader.Prec * InHeader.NV);
         i < InHeader.NC;
         i++ ){
      if ( InArray.LCName > 0 ){
         fread( CaseName, (int)InArray.LCName, 1, in);
         fwrite( CaseName, (int)InArray.LCName, 1, out);
      }
      fread( pData, RecordLen, 1, in);
      if (InHeader.Prec == 4) {
         /*-- compute sum of variables --*/
         for ( j = 0, sumF = (float)0, pF = (float *)pData;
               j < InHeader.NV;
               j++, pF++ )
            sumF += *pF;
         /*-- write results to output file --*/
         fwrite( &sumF, 4, 1, out);
      }
      else {
         /*-- compute sum of variables --*/
         for ( j = 0, sumD = (double)0, pD = (double *)pData;
               j < InHeader.NV;
               j++, pD++ )
            sumD += *pD;
         /*-- write results to output file --*/
         fwrite( &sumD, 8, 1, out);
      }
      /*-- write remaining part of record to the output --*/
      fwrite( pData, RecordLen, 1, out);
   }
   /*-- free allocated memory buffer --*/
   free(pData);
}

/*-------------------------------- end of ProcessData --------------------------*/

void fcopy( FILE * out, FILE * in, unsigned int size )
/*-- copy SIZE bytes from input stream to output stream using dynamically
   allocated buffer --*/
{
   BYTE * p;

   if ( size == 0 )
      return;
   if ( (p = malloc(size)) == NULL ){
      printf("\n Memory allocation error.");
      exit(1);
   }
   fread( p, size, 1, in);
   fwrite( p, size, 1, out);
   free(p);
}

/*--------------------------------- end of fcopy -------------------------------*/

void Ceil512( long * pL )
/*-- adjust number to nearest multiple of 512 --*/
{
  ldiv_t S;

  S = ldiv( *pL, 512L );
  if ( S.rem != 0L )
     *pL = (S.quot + 1L) * 512L;
}

/*--------------------------------- end of Ceil512 ------------------------------*/

