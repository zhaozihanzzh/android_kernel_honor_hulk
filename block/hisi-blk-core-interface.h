#ifndef __HISI_BLK_CORE_INTERFACE_H__
#define __HISI_BLK_CORE_INTERFACE_H__
#include <linux/blkdev.h>

extern void _cfi_hisi_blk_queue_usr_ctrl_recovery_timer_expire(unsigned long data);
extern void hisi_blk_queue_usr_ctrl_recovery_timer_expire(unsigned long data);
extern ssize_t __cfi_hisi_queue_status_show(struct request_queue *q, char *page);
extern ssize_t hisi_queue_status_show(struct request_queue *q, char *page);
#if defined(CONFIG_HISI_DEBUG_FS) || defined(CONFIG_HISI_BLK_DEBUG)
extern ssize_t __cfi_hisi_queue_io_prio_sim_show(struct request_queue * q, char *page);
extern ssize_t hisi_queue_io_prio_sim_show(struct request_queue * q, char *page);
extern ssize_t __cfi_hisi_queue_io_prio_sim_store(
	struct request_queue *q, const char *page, size_t count);
extern ssize_t hisi_queue_io_prio_sim_store(
	struct request_queue *q, const char *page, size_t count);
#endif
#endif

