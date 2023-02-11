#include <stdlib.h>
#include "towers.h"

int main(int argc, char **argv)
{
      int n = 5;
      int from = 2;
      int dest = 3;

      if (argc > 1)
      {
            if (argc == 2)
            {
                  n = atoi(argv[1]);
                  towers(n, from, dest);
            }
            else if (argc >= 3)
            {
                  n = atoi(argv[1]);
                  from = atoi(argv[2]);
                  dest = atoi(argv[3]);
                  towers(n, from, dest);
            }
            else
            {
                  exit(-1);
            }
      }
      else
      {
            towers(n, from, dest);
      }

      exit(0);
}


