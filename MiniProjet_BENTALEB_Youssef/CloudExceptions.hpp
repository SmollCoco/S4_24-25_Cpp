#include <exception>
#include <string>

class CloudException : public std::exception {
    protected:
        std::string msg_;
    public:
        explicit CloudException(const std::string& message) : msg_(message) {}
        virtual const char* what() const noexcept override {
            return msg_.c_str();
        }
};

class AllocationException : public CloudException {
    public:
        explicit AllocationException(const std::string& message) : CloudException(message) {}
        virtual const char* what() const noexcept override {
            return ("Allocation Error: " + msg_).c_str();
        }
};

class FileException : public CloudException {
    public:
        explicit FileException(const std::string& message) : CloudException(message) {}
        virtual const char* what() const noexcept override {
            return ("File Error: " + msg_).c_str();
        }
};

class ServerInactiveException : public CloudException {
    public:
        explicit ServerInactiveException(const std::string& message) : CloudException(message) {}
        virtual const char* what() const noexcept override {
            return ("Erreur de serveur inactif: " + msg_).c_str();
        }
};
