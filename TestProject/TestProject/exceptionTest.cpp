#include <iostream>
#include <string>

// ����� ���� ������ �⺻ Ŭ����
class Exception {
public:
    explicit Exception(const std::string& message) : message_(message) {}

    // ���� �Ҹ��� �߰�
    virtual ~Exception() {}

    // ���� �޽����� ��ȯ�ϴ� ���� �Լ�
    virtual const char* what() const noexcept {
        return message_.c_str();
    }

private:
    std::string message_;
};

// Exception�� ��ӹ��� Ŀ���� ���� Ŭ����
class CustomException : public Exception {
public:
    explicit CustomException(const std::string& message, int errorCode)
        : Exception(message), errorCode_(errorCode) {}

    // CustomException���� �ִ� ��� �Լ�
    int getErrorCode() const {
        return errorCode_;
    }

private:
    int errorCode_;
};

void throwException() {
    // CustomException ��ü�� ������ ���� (���纻�� ������)
    CustomException ex("CustomException occurred", 404);
    throw ex;  // �Լ� ���� �� ���ÿ��� ������ ��ü�� ���纻�� ������
}

int mainException() {
    try {
        throwException();
    }
    catch (Exception& e) { // Exception�� ������ ���� -> ��ü �߸� �߻�
        std::cout << e.what() << std::endl;

        // �Ļ� Ŭ������ ��� ���� �õ�
        try {
            CustomException& ce = dynamic_cast<CustomException&>(e);
            std::cout << "Error code: " << ce.getErrorCode() << std::endl;
        }
        catch (std::bad_cast&) {
            // ��ü �߸����� ���� CustomException���� ĳ���� ����
            std::cout << "Caught bad_cast: Object slicing occurred, cannot cast to CustomException." << std::endl;
        }
    }

    return 0;
}