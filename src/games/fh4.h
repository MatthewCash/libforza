#pragma once

int init_fh4(struct pollfd *pollfd);

int destruct_fh4(void);

int handle_fh4_socket_data(void);
