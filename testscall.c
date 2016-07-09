#include <linux/kernel.h>
#include <stdio.h>
#include <sys/sysinfo.h>

int main ()
{
 /* Conversion constants. */
 long minute = 60;
 long hour = 60 * 60;
 long day = 60*60* 24;
 double meg = 1024 * 1024;



 struct sysinfo pointer_to_sysinfo;
 sysinfo (&pointer_to_sysinfo);
//uptime
 printf ("Sytem uptime: %ld is equal ", pointer_to_sysinfo.uptime);
 printf (" %ld days, %ld:%02ld:%02ld  \n\n", pointer_to_sysinfo.uptime / day, (pointer_to_sysinfo.uptime % day) / hour,
     (pointer_to_sysinfo.uptime % hour) / minute, pointer_to_sysinfo.uptime % minute);
//memory
 printf ("total RAM: %5.1f MB\t", pointer_to_sysinfo.totalram / meg);
 printf ("free RAM: %5.1f MB\n", pointer_to_sysinfo.freeram / meg);
 printf   ("Amount of shared memory: %5.1f MB\t", pointer_to_sysinfo.sharedram / meg);
 printf ("Memory used by buffers: %5.1f MB\n", pointer_to_sysinfo.bufferram / meg);
 printf ("Total high memory size: %5.1f \t Available high memory size: %5.1f\n", pointer_to_sysinfo.totalhigh / meg, pointer_to_sysinfo.freehigh / meg);
 printf ("Available high memory size: %5f\n\n", pointer_to_sysinfo.mem_unit );
 //swap
 printf ("Total swap space size: %5.1f MB \t Free Swap: %6.1f MB\n\n", pointer_to_sysinfo.totalswap / meg, pointer_to_sysinfo.freeswap / meg);
//process
 printf ("process count : %d\n\n", pointer_to_sysinfo.procs );
 //Load Average
  float           new_table[3];
  float           div_by_num;
  div_by_num=(float)(1<<SI_LOAD_SHIFT);
  new_table[0]=((float)pointer_to_sysinfo.loads[0])/div_by_num;
  new_table[1]=((float)pointer_to_sysinfo.loads[1])/div_by_num;
  new_table[2]=((float)pointer_to_sysinfo.loads[2])/div_by_num;
 printf ("Load Average 1, 5, and 15 minute\n\t1: %f \t5: %f\t15: %f\n", new_table[0],new_table[0],new_table[0]);

 return 0;
}
