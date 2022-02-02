#pragma once

int start_fm7_socket(void);

int destruct_fm7(const int sockfd);

int handle_fm7_socket_data(const int sockfd);
