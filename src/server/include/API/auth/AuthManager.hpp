//
// Created by vladislav on 14.05.22.
//

#ifndef SERVER_V0_1_AUTHMANAGER_HPP
#define SERVER_V0_1_AUTHMANAGER_HPP

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <boost/asio/strand.hpp>
#include <iostream>
#include <memory>
#include <string>


namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
using error_code = boost::system::error_code;


template<typename Body, typename Allocator, typename Send>
class AuthManager : public std::enable_shared_from_this<AuthManager<Body, Allocator, Send>> {
public:
    AuthManager(http::request<Body, http::basic_fields<Allocator>> &&req, Send &&send);

    virtual void handle_request() = 0;

protected:

    virtual http::file_body::value_type create_body(const char* file_path) = 0;
    // virtual http::file_body::value_type create_responce() = 0;

    Send _send;
    http::request<Body, http::basic_fields<Allocator>> _request;
};

template<typename Body, typename Allocator, typename Send>
AuthManager<Body, Allocator, Send>::AuthManager(http::request<Body, http::basic_fields<Allocator>> &&req, Send &&send)
        : _request(std::move(req)),
          _send(std::forward<Send>(send)) {}

template<typename Body, typename Allocator, typename Send>
class GetAuthManager : public AuthManager<Body, Allocator, Send> {
public:
    GetAuthManager(http::request<Body, http::basic_fields<Allocator>> &&req, Send &&send)
            : AuthManager<Body, Allocator, Send>(std::move(req), std::forward<Send>(send)) {}

    void handle_request() final;

private:
    http::file_body::value_type create_body(const char* file_path) final;
    // http::file_body::value_type create_responce() final;
};

// GET_AuthManager, POST_AuthManager, PUT_AuthManager ...

template<typename Body, typename Allocator, typename Send>
void GetAuthManager<Body, Allocator, Send>::handle_request() {
    http::file_body::value_type body = create_body("./doc_root/auth.json");

    http::response<http::file_body> res{
            std::piecewise_construct,
            std::make_tuple(std::move(body)),
            std::make_tuple(http::status::ok, this->_request.version()),
    };

    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, "text/json");
    res.content_length(res.body().size());
    res.keep_alive(this->_request.keep_alive());

    return this->_send(std::move(res));
}

template<typename Body, typename Allocator, typename Send>
http::file_body::value_type GetAuthManager<Body, Allocator, Send>::create_body(const char* file_path) {
    http::file_body::value_type body;
    error_code ec_http_body;
    body.open(file_path, beast::file_mode::scan, ec_http_body);

    if (ec_http_body) {
        // Logger::Error(__LINE__, __FILE__, "error in body.open()");
    }
    return body;
}

#endif //SERVER_V0_1_AUTHMANAGER_HPP
