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
typedef  scalar_t__ uint64_t ;
typedef  unsigned int uint32_t ;

/* Variables and functions */
 int MIN (int,int) ; 
 int /*<<< orphan*/  OCTEON_PCI_ENDIAN_64BIT_SWAP ; 
 int /*<<< orphan*/  buf_size ; 
 int /*<<< orphan*/  console_addr_array ; 
 int /*<<< orphan*/  input_base_addr ; 
 int /*<<< orphan*/  input_read_index ; 
 int /*<<< orphan*/  input_write_index ; 
 unsigned int num_consoles ; 
 int octeon_pci_console_buffer_free_bytes (unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  octeon_pci_console_desc_t ; 
 int /*<<< orphan*/  octeon_pci_console_t ; 
 int /*<<< orphan*/  octeon_pci_write_mem (scalar_t__,char const*,int,int /*<<< orphan*/ ) ; 
 unsigned int octeon_read_mem32 (scalar_t__) ; 
 scalar_t__ octeon_read_mem64 (scalar_t__) ; 
 int /*<<< orphan*/  octeon_write_mem32 (scalar_t__,unsigned int) ; 
 scalar_t__ offsetof (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,unsigned int) ; 

int octeon_pci_console_host_write(uint64_t console_desc_addr, unsigned int console_num, const char * buffer, int write_reqest_size, uint32_t flags)
{
    if (!console_desc_addr)
        return -1;

    /* Get global pci console information and look up specific console structure. */
    uint32_t num_consoles = octeon_read_mem32(console_desc_addr + offsetof(octeon_pci_console_desc_t, num_consoles));
//    printf("Num consoles: %d, buf size: %d\n", num_consoles, console_buffer_size);
    if (console_num >= num_consoles)
    {
        printf("ERROR: attempting to read non-existant console: %d\n", console_num);
        return(-1);
    }
    uint64_t console_addr = octeon_read_mem64(console_desc_addr + offsetof(octeon_pci_console_desc_t, console_addr_array) + console_num *8);
//    printf("Console %d is at 0x%llx\n", console_num, (long long)console_addr);

    uint32_t console_buffer_size = octeon_read_mem32(console_addr + offsetof(octeon_pci_console_t, buf_size));
    /* Check to see if any data is available */
    uint32_t rd_idx, wr_idx;
    uint64_t base_addr;

    base_addr = octeon_read_mem64(console_addr + offsetof(octeon_pci_console_t, input_base_addr));
    rd_idx = octeon_read_mem32(console_addr + offsetof(octeon_pci_console_t, input_read_index));
    wr_idx = octeon_read_mem32(console_addr + offsetof(octeon_pci_console_t, input_write_index));

//    printf("Input base: 0x%llx, rd: %d(0x%x), wr: %d(0x%x)\n", (long long)base_addr, rd_idx, rd_idx, wr_idx, wr_idx);
    int bytes_to_write = octeon_pci_console_buffer_free_bytes(console_buffer_size, wr_idx, rd_idx);
    if (bytes_to_write <= 0)
        return bytes_to_write;
    bytes_to_write = MIN(bytes_to_write, write_reqest_size);
    /* Check to see if what we want to write is not contiguous, and limit ourselves to the contiguous block*/
    if (wr_idx + bytes_to_write >= console_buffer_size)
        bytes_to_write = console_buffer_size - wr_idx;

//    printf("Attempting to write %d bytes, (buf size: %d)\n", bytes_to_write, write_reqest_size);

    octeon_pci_write_mem(base_addr + wr_idx, buffer, bytes_to_write, OCTEON_PCI_ENDIAN_64BIT_SWAP);
    octeon_write_mem32(console_addr + offsetof(octeon_pci_console_t, input_write_index), (wr_idx + bytes_to_write)%console_buffer_size);

    return bytes_to_write;

}