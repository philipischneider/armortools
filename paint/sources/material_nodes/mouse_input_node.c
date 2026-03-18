
#include "../global.h"

void mouse_input_node_init() {
	any_array_push(nodes_material_input, mouse_input_node_def);
	any_map_set(parser_material_node_vectors, "MOUSE_INPUT", mouse_input_node_vector);
}

char *mouse_input_node_vector(ui_node_t *node, ui_node_socket_t *socket) {
	parser_material_kong->frag_mouse = true;
	if (socket == node->outputs->buffer[0]) { // Position
		return "float3(constants.mouse_pos.x, constants.mouse_pos.y, 0.0)";
	}
	else if (socket == node->outputs->buffer[1]) { // Direction
		return "mouse_dir";
	}
	else { // Stroke Direction (UV-encoded for flow maps)
		return "mouse_stroke";
	}
}
