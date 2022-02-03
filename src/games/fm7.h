#pragma once

int init_fm7(struct pollfd *pollfd);

int destruct_fm7(void);

int handle_fm7_socket_data(void);
