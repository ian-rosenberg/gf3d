#include "gf3d_vertex_buffers.h"
#include "simple_logger.h"

typedef struct
{
	VkBuffer vertex_buffer;
	VkDevice *logDevice;
	VkPhysicalDevice *physDevice;
}gf3d_vertex_buffer_manager;

static gf3d_vertex_buffer_manager vertexBufferManager = { 0 };

static VkVertexInputAttributeDescription	attrDescriptions[2] = { 0 };
static VkVertexInputBindingDescription		bindDescription = { 0 };

void vertexBufferInit(VkDevice *log, VkPhysicalDevice *phys){
	vertexBufferManager.logDevice = log;
	vertexBufferManager.physDevice = phys;

	bindDescription.binding = 0;
	bindDescription.stride = sizeof(Vertex);
	bindDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
	attrDescriptions[0].binding = 0;
	attrDescriptions[0].location = 0;
	attrDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
	attrDescriptions[0].offset = offsetof(Vertex, pos);
	attrDescriptions[1].binding = 0;
	attrDescriptions[1].location = 0;
	attrDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
	attrDescriptions[1].offset = offsetof(Vertex, color);
}