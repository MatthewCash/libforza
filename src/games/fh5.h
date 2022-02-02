#pragma once

int init_fh5(struct pollfd *pollfd);

int destruct_fh5(void);

int handle_fh5_socket_data(void);
