/* 
 * File:   rupSM.c
 * Author: Bastian Ruppert
 * Date: 28.01.2010
 */

#include <unistd.h>
#include <sys/mman.h>

#include <defs.h>
#include "rupSm.h"

/**
 * \brief Create and open Shared Mem
 * \param name Name des Shared Mem
 * \param memsize size of mem
 * \param pres_fd will hold the shared mem fd on succesful return
 * \return NULL on failure, or pointer to shared mem after success
 * 
 * If the shared mem region already exists, it will be unlinked 
 * and closed
 */
void * rupSmCreateMem(char * name,int memsize, int * pres_fd)
{
  int fd;
  void * pmem;
  if((fd = shm_open(name, O_RDWR, PERM_FILE))!=-1)
    {
      (void)shm_unlink(name);
      (void)close(fd);
    }

  ec_neg1(fd = shm_open(name, O_RDWR | O_CREAT, PERM_FILE))

  ec_neg1(ftruncate(fd,memsize))

  pmem = mmap(NULL,memsize,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  
  ec_cmp(pmem,MAP_FAILED)

  *pres_fd = fd;
  return pmem;
EC_CLEANUP_BGN
  (void)shm_unlink(name);
  (void)close(fd);
  return NULL;
EC_CLEANUP_END
}


/**
 * \brief Opens Shared Mem
 * \param name Name des Shared Mem
 * \param memsize size of mem
 * \param pres_fd will hold the shared mem fd on succesful return
 * \return NULL on failure, or pointer to shared mem after success
 * 
 */
void * rupSmOpenMem(char * name,int memsize,int * res_fd)
{
  int fd;
  void * pmem;
  ec_neg1(fd = shm_open(name, O_RDWR, PERM_FILE))

  pmem = mmap(NULL,memsize,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  ec_cmp(pmem,MAP_FAILED)
  *res_fd = fd;

  return pmem;
EC_CLEANUP_BGN
  (void)shm_unlink(name);
  (void)close(fd);
  return NULL;
EC_CLEANUP_END
}

/*int rupSmClose(char * linkname,int fd)
{
  ec_neg1(shm_unlink(linkname))
  ec_neg1(close(fd))
  return 0;
EC_CLEANUP_BGN
  return -1;
EC_CLEANUP_END   
}*/
