#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct radeon_ring {int /*<<< orphan*/  ring_size; } ;
struct TYPE_4__ {int /*<<< orphan*/  installed; } ;
struct radeon_device {int /*<<< orphan*/  dev; struct radeon_ring* ring; TYPE_2__ irq; TYPE_1__* asic; int /*<<< orphan*/  mc_fw; int /*<<< orphan*/  rlc_fw; int /*<<< orphan*/  ce_fw; int /*<<< orphan*/  pfp_fw; int /*<<< orphan*/  me_fw; } ;
struct TYPE_3__ {int /*<<< orphan*/ * copy; } ;

/* Variables and functions */
 size_t CAYMAN_RING_TYPE_CP1_INDEX ; 
 size_t CAYMAN_RING_TYPE_CP2_INDEX ; 
 size_t CAYMAN_RING_TYPE_DMA1_INDEX ; 
 int /*<<< orphan*/  CAYMAN_WB_DMA1_RPTR_OFFSET ; 
 scalar_t__ CP_RB0_RPTR ; 
 scalar_t__ CP_RB0_WPTR ; 
 scalar_t__ CP_RB1_RPTR ; 
 scalar_t__ CP_RB1_WPTR ; 
 scalar_t__ CP_RB2_RPTR ; 
 scalar_t__ CP_RB2_WPTR ; 
 scalar_t__ DMA0_REGISTER_OFFSET ; 
 scalar_t__ DMA1_REGISTER_OFFSET ; 
 int /*<<< orphan*/  DMA_PACKET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DMA_PACKET_NOP ; 
 scalar_t__ DMA_RB_RPTR ; 
 scalar_t__ DMA_RB_WPTR ; 
 int /*<<< orphan*/  DRM_ERROR (char*,...) ; 
 size_t R600_RING_TYPE_DMA_INDEX ; 
 int /*<<< orphan*/  R600_WB_DMA_RPTR_OFFSET ; 
 int /*<<< orphan*/  RADEON_CP_PACKET2 ; 
 size_t RADEON_RING_TYPE_GFX_INDEX ; 
 int /*<<< orphan*/  RADEON_WB_CP1_RPTR_OFFSET ; 
 int /*<<< orphan*/  RADEON_WB_CP2_RPTR_OFFSET ; 
 int /*<<< orphan*/  RADEON_WB_CP_RPTR_OFFSET ; 
 int cayman_dma_resume (struct radeon_device*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,int) ; 
 int evergreen_blit_init (struct radeon_device*) ; 
 int /*<<< orphan*/  r600_blit_fini (struct radeon_device*) ; 
 int r600_vram_scratch_init (struct radeon_device*) ; 
 int radeon_fence_driver_start_ring (struct radeon_device*,size_t) ; 
 int radeon_ib_pool_init (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_irq_kms_fini (struct radeon_device*) ; 
 int radeon_irq_kms_init (struct radeon_device*) ; 
 int radeon_ring_init (struct radeon_device*,struct radeon_ring*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int,int,int /*<<< orphan*/ ) ; 
 int radeon_vm_manager_init (struct radeon_device*) ; 
 int radeon_wb_init (struct radeon_device*) ; 
 int si_cp_load_microcode (struct radeon_device*) ; 
 int si_cp_resume (struct radeon_device*) ; 
 int /*<<< orphan*/  si_gpu_init (struct radeon_device*) ; 
 int si_init_microcode (struct radeon_device*) ; 
 int si_irq_init (struct radeon_device*) ; 
 int /*<<< orphan*/  si_irq_set (struct radeon_device*) ; 
 int si_mc_load_microcode (struct radeon_device*) ; 
 int /*<<< orphan*/  si_mc_program (struct radeon_device*) ; 
 int si_pcie_gart_enable (struct radeon_device*) ; 
 int si_rlc_init (struct radeon_device*) ; 

__attribute__((used)) static int si_startup(struct radeon_device *rdev)
{
	struct radeon_ring *ring;
	int r;

	if (!rdev->me_fw || !rdev->pfp_fw || !rdev->ce_fw ||
	    !rdev->rlc_fw || !rdev->mc_fw) {
		r = si_init_microcode(rdev);
		if (r) {
			DRM_ERROR("Failed to load firmware!\n");
			return r;
		}
	}

	r = si_mc_load_microcode(rdev);
	if (r) {
		DRM_ERROR("Failed to load MC firmware!\n");
		return r;
	}

	r = r600_vram_scratch_init(rdev);
	if (r)
		return r;

	si_mc_program(rdev);
	r = si_pcie_gart_enable(rdev);
	if (r)
		return r;
	si_gpu_init(rdev);

#if 0
	r = evergreen_blit_init(rdev);
	if (r) {
		r600_blit_fini(rdev);
		rdev->asic->copy = NULL;
		dev_warn(rdev->dev, "failed blitter (%d) falling back to memcpy\n", r);
	}
#endif
	/* allocate rlc buffers */
	r = si_rlc_init(rdev);
	if (r) {
		DRM_ERROR("Failed to init rlc BOs!\n");
		return r;
	}

	/* allocate wb buffer */
	r = radeon_wb_init(rdev);
	if (r)
		return r;

	r = radeon_fence_driver_start_ring(rdev, RADEON_RING_TYPE_GFX_INDEX);
	if (r) {
		dev_err(rdev->dev, "failed initializing CP fences (%d).\n", r);
		return r;
	}

	r = radeon_fence_driver_start_ring(rdev, CAYMAN_RING_TYPE_CP1_INDEX);
	if (r) {
		dev_err(rdev->dev, "failed initializing CP fences (%d).\n", r);
		return r;
	}

	r = radeon_fence_driver_start_ring(rdev, CAYMAN_RING_TYPE_CP2_INDEX);
	if (r) {
		dev_err(rdev->dev, "failed initializing CP fences (%d).\n", r);
		return r;
	}

	r = radeon_fence_driver_start_ring(rdev, R600_RING_TYPE_DMA_INDEX);
	if (r) {
		dev_err(rdev->dev, "failed initializing DMA fences (%d).\n", r);
		return r;
	}

	r = radeon_fence_driver_start_ring(rdev, CAYMAN_RING_TYPE_DMA1_INDEX);
	if (r) {
		dev_err(rdev->dev, "failed initializing DMA fences (%d).\n", r);
		return r;
	}

	/* Enable IRQ */
	if (!rdev->irq.installed) {
		r = radeon_irq_kms_init(rdev);
		if (r)
			return r;
	}

	r = si_irq_init(rdev);
	if (r) {
		DRM_ERROR("radeon: IH init failed (%d).\n", r);
		radeon_irq_kms_fini(rdev);
		return r;
	}
	si_irq_set(rdev);

	ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
	r = radeon_ring_init(rdev, ring, ring->ring_size, RADEON_WB_CP_RPTR_OFFSET,
			     CP_RB0_RPTR, CP_RB0_WPTR,
			     0, 0xfffff, RADEON_CP_PACKET2);
	if (r)
		return r;

	ring = &rdev->ring[CAYMAN_RING_TYPE_CP1_INDEX];
	r = radeon_ring_init(rdev, ring, ring->ring_size, RADEON_WB_CP1_RPTR_OFFSET,
			     CP_RB1_RPTR, CP_RB1_WPTR,
			     0, 0xfffff, RADEON_CP_PACKET2);
	if (r)
		return r;

	ring = &rdev->ring[CAYMAN_RING_TYPE_CP2_INDEX];
	r = radeon_ring_init(rdev, ring, ring->ring_size, RADEON_WB_CP2_RPTR_OFFSET,
			     CP_RB2_RPTR, CP_RB2_WPTR,
			     0, 0xfffff, RADEON_CP_PACKET2);
	if (r)
		return r;

	ring = &rdev->ring[R600_RING_TYPE_DMA_INDEX];
	r = radeon_ring_init(rdev, ring, ring->ring_size, R600_WB_DMA_RPTR_OFFSET,
			     DMA_RB_RPTR + DMA0_REGISTER_OFFSET,
			     DMA_RB_WPTR + DMA0_REGISTER_OFFSET,
			     2, 0x3fffc, DMA_PACKET(DMA_PACKET_NOP, 0, 0, 0, 0));
	if (r)
		return r;

	ring = &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX];
	r = radeon_ring_init(rdev, ring, ring->ring_size, CAYMAN_WB_DMA1_RPTR_OFFSET,
			     DMA_RB_RPTR + DMA1_REGISTER_OFFSET,
			     DMA_RB_WPTR + DMA1_REGISTER_OFFSET,
			     2, 0x3fffc, DMA_PACKET(DMA_PACKET_NOP, 0, 0, 0, 0));
	if (r)
		return r;

	r = si_cp_load_microcode(rdev);
	if (r)
		return r;
	r = si_cp_resume(rdev);
	if (r)
		return r;

	r = cayman_dma_resume(rdev);
	if (r)
		return r;

	r = radeon_ib_pool_init(rdev);
	if (r) {
		dev_err(rdev->dev, "IB initialization failed (%d).\n", r);
		return r;
	}

	r = radeon_vm_manager_init(rdev);
	if (r) {
		dev_err(rdev->dev, "vm manager initialization failed (%d).\n", r);
		return r;
	}

	return 0;
}