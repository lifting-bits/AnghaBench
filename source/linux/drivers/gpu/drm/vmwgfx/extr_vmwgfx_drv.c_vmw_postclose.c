#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct vmw_fpriv {int /*<<< orphan*/  tfile; } ;
struct drm_file {int dummy; } ;
struct drm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct vmw_fpriv*) ; 
 int /*<<< orphan*/  ttm_object_file_release (int /*<<< orphan*/ *) ; 
 struct vmw_fpriv* vmw_fpriv (struct drm_file*) ; 

__attribute__((used)) static void vmw_postclose(struct drm_device *dev,
			 struct drm_file *file_priv)
{
	struct vmw_fpriv *vmw_fp = vmw_fpriv(file_priv);

	ttm_object_file_release(&vmw_fp->tfile);
	kfree(vmw_fp);
}