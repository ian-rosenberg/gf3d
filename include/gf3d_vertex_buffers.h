#ifndef __GF3D_VERTEX_BUFFERS_H__
#define __GF3d_VERTEX_BUFFERS_H__

#include <vulkan\vulkan.h>
#include <cglm\call.h>

const Vertex vertices[] =
{
	{ { 0.0f, -0.5f }, { 1.0f, 1.0f, 0.0f } },
	{ { 0.5f, 0.5f }, { 0.0f, 1.0f, 1.0f } },
	{ { -0.5f, 0.5f }, { 1.0f, 0.0f, 1.0f } }
};

typedef struct
{
	vec2 pos;
	vec3 color;
} Vertex;

/**
* @brief return the binding description
*/
static VkVertexInputBindingDescription getBindingDescription();

/**
* @brief return the attribute descriptions
*/
static void getAttributeDescriptions(VkVertexInputAttributeDescription *attributeDescriptions);

/**
* @brief Create a vertex buffer with previously
*
* @param logDevice        The logical device to reference
* @param physDevice		 The physcial device to reference
*/
void vertexBufferInit(VkDevice *log, VkPhysicalDevice *phys);

/**
* @brief Create a vertex buffer with previously
*
* @return The vulkan buffer that was created
*/
VkBuffer* createVertexBuffer();

#endif // !__GF3D_VERTEX_BUFFERS_H__
