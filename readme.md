Create your own HTTP server

- Accept HTTP requests (GET, POST, DELETE)

- Respond correctly with status codes and content 200->ok 404->Not Found etc..

- Serve static websites (HTML, CSS, JS files)

- Handle file uploads

- Support configuration files (similar to NGINX style)

- Work with a web browser

- Be fully non-blocking using poll() (or select(), epoll(), or kqueue())

- Handle multiple connections simultaneously (multiplexing)

- Support CGI (e.g., running a PHP or Python script)

- Stress-test ready (it must never crash or hang)


1. Core Developer (Network + IO)		

Set up sockets

Handle connections using poll()

Manage client connections (fd, buffer)
| socket, poll, accept, recv, send, non-blocking, fd |

2. HTTP Protocol Developer

Parse HTTP requests (method, headers, body)

Generate correct HTTP responses

Implement GET, POST, DELETE logic
| HTTP status codes, RequestParser, ResponseBuilder, chunked, content-length |

3. Config & CGI Developer

Implement configuration file parsing (port, route, error pages, etc.)

Configure static routes, uploads, error pages

Handle CGI execution (fork, execve)
| ConfigParser, routes, CGI, upload, directory listing, .php |