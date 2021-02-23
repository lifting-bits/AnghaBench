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
typedef  int /*<<< orphan*/  VkBool32 ;

/* Variables and functions */
 int /*<<< orphan*/  VK_FALSE ; 
 int /*<<< orphan*/  VK_TRUE ; 
 int /*<<< orphan*/  VULKAN_SYMBOL_WRAPPER_LOAD_INSTANCE_SYMBOL (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vkCreateInstance ; 
 int /*<<< orphan*/  vkEnumerateInstanceExtensionProperties ; 
 int /*<<< orphan*/  vkEnumerateInstanceLayerProperties ; 

VkBool32 vulkan_symbol_wrapper_load_global_symbols(void)
{
    if (!VULKAN_SYMBOL_WRAPPER_LOAD_INSTANCE_SYMBOL(NULL, "vkCreateInstance", vkCreateInstance)) return VK_FALSE;
    if (!VULKAN_SYMBOL_WRAPPER_LOAD_INSTANCE_SYMBOL(NULL, "vkEnumerateInstanceExtensionProperties", vkEnumerateInstanceExtensionProperties)) return VK_FALSE;
    if (!VULKAN_SYMBOL_WRAPPER_LOAD_INSTANCE_SYMBOL(NULL, "vkEnumerateInstanceLayerProperties", vkEnumerateInstanceLayerProperties)) return VK_FALSE;
    return VK_TRUE;
}