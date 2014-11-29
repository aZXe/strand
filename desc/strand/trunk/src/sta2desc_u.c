//---------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <sys\stat.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "Constants.h"
#include "stadev.h"
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
  char Varname [STAMAX_VARNAMELEN  + 1];
  char buf[1000], *p;
  HSTAFILE hSta;
  FILE *handle;
  int i, count, itmp;

  if (argc < 2 || argc > 3) {
    printf("sta2desc - Convert .sta file to .desc file\nSyntax:\tsta2desc filename.sta [filename.desc]\n");
    return 0;
  }

  hSta = StaOpenFile (argv[1]);
  if ( hSta == 0 ) {
    printf("Error : Cannot open file %s!\n", argv[1]);
    return -1;
  }
  printf(" * Open file %s\n", argv[1]);

  if (argc == 3)
    strcpy(buf, argv[2]);
  else {
    p = strstr(argv[1], ".");
    strncpy(buf, argv[1], p - argv[1]);
    strcat(buf, ".desc");
  }

//  handle = open(buf, O_CREAT | O_BINARY | O_TRUNC, S_IWRITE | S_IREAD);
  handle = fopen(buf, "wb");
  if (handle < 0) {
    printf("Error : Cannot open file %s!\n", argv[2]);
    StaCloseFile(hSta);
    printf(" * Close file %s\n", argv[1]);
    return -1;
  }
  printf(" * Create file %s\n", buf);

  count = StaGetNVars(hSta);
  Varname [STAMAX_VARNAMELEN ] = 0;

  //Count
  fwrite(&count, sizeof(count), 1, handle);
  printf(" * %d vars\n", count);

  for (i = 1; i <= count; i++) {
    StaGetVarName (hSta, i, Varname);
    p = strstr(Varname, " ");
    if (p) *p = 0;
    printf(" * Write \"%s\"\n", Varname);

    //Type
    itmp = STA_VAR;
    fwrite(&itmp, sizeof(itmp), 1, handle);

    //Name
    itmp = strlen(Varname);
    fwrite(&itmp, sizeof(itmp), 1, handle);
    fwrite(Varname, itmp + 1, 1, handle);

    //Description
    itmp = 0;
    fwrite(&itmp, sizeof(itmp), 1, handle);
    fwrite(&itmp, 1, 1, handle);

    //StaFileName
    itmp = strlen(argv[1]);
    fwrite(&itmp, sizeof(itmp), 1, handle);
    fwrite(argv[1], itmp + 1, 1, handle);

    //NumVar
    fwrite(&i, sizeof(i), 1, handle);

    //Data
    itmp = 0;
    fwrite(&itmp, sizeof(itmp), 1, handle);
  }

  fclose(handle);
  printf(" * Close file %s\n", buf);
  StaCloseFile(hSta);
  printf(" * Close file %s\n", argv[1]);
  return 0;
}
//---------------------------------------------------------------------------

