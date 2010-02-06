/* 
 * File:   rupSM.c
 * Author: Bastian Ruppert
 * Date: 28.01.2010
 */

#ifndef __rupSm_h__
#define __rupSm_h__

extern void * rupSmCreateMem(char * name,int memsize, int * res_fd);

extern void * rupSmOpenMem(char * name,int memsize,int * res_fd);

/*int rupSmClose(char * linkname,int fd)
{
  ec_neg1(shm_unlink(linkname))
  ec_neg1(close(fd))
  return 0;
EC_CLEANUP_BGN
  return -1;
EC_CLEANUP_END   
}*/

#endif
