/* Copyright (c) 2015-2018, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef MDSS_SYNC_H
#define MDSS_SYNC_H

#include <linux/types.h>
#include <linux/errno.h>

struct mdss_fence;
struct mdss_timeline;

#if defined(CONFIG_SYNC_FILE)
struct mdss_timeline *mdss_create_timeline(const char *name);

void mdss_destroy_timeline(struct mdss_timeline *tl);

struct mdss_fence *mdss_get_sync_fence(
		struct mdss_timeline *tl, const char *fence_name,
		u32 *timestamp, int offset);

void mdss_resync_timeline(struct mdss_timeline *tl);

u32 mdss_get_timeline_commit_ts(struct mdss_timeline *tl);

u32 mdss_get_timeline_retire_ts(struct mdss_timeline *tl);

int mdss_inc_timeline(struct mdss_timeline *tl, int increment);

void mdss_put_sync_fence(struct mdss_fence *fence);

int mdss_wait_sync_fence(struct mdss_fence *fence,
		long timeout);

struct mdss_fence *mdss_get_fd_sync_fence(int fd);

int mdss_get_sync_fence_fd(struct mdss_fence *fence);
const char *mdss_get_sync_fence_name(struct mdss_fence *fence);
#else
static inline
struct mdss_timeline *mdss_create_timeline(const char *name)
{
	return NULL;
}

static inline
void mdss_destroy_timeline(struct mdss_timeline *tl)
{
}

static inline
struct mdss_fence *mdss_get_sync_fence(
		struct mdss_timeline *tl, const char *fence_name,
		u32 *timestamp, int offset)
{
	return NULL;
}

static inline
void mdss_resync_timeline(struct mdss_timeline *tl)
{
}

static inline
int mdss_inc_timeline(struct mdss_timeline *tl, int increment)
{
	return 0;
}

static inline
u32 mdss_get_timeline_commit_ts(struct mdss_timeline *tl)
{
	return 0;
}

static inline
u32 mdss_get_timeline_retire_ts(struct mdss_timeline *tl)
{
	return 0;
}

static inline
void mdss_put_sync_fence(struct mdss_fence *fence)
{
}

static inline
int mdss_wait_sync_fence(struct mdss_fence *fence,
		long timeout)
{
	return 0;
}

static inline
struct mdss_fence *mdss_get_fd_sync_fence(int fd)
{
	return NULL;
}

static inline
int mdss_get_sync_fence_fd(struct mdss_fence *fence)
{
	return -EBADF;
}
const char *mdss_get_sync_fence_name(struct mdss_fence *fence)
{
	return NULL;
}
}
#endif

#endif /* MDSS_SYNC_H */
