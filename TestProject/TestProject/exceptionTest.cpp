#include <iostream>
#include <string>

// 사용자 정의 예외의 기본 클래스
class Exception {
public:
    explicit Exception(const std::string& message) : message_(message) {}

    // 가상 소멸자 추가
    virtual ~Exception() {}

    // 예외 메시지를 반환하는 가상 함수
    virtual const char* what() const noexcept {
        return message_.c_str();
    }

private:
    std::string message_;
};

// Exception을 상속받은 커스텀 예외 클래스
class CustomException : public Exception {
public:
    explicit CustomException(const std::string& message, int errorCode)
        : Exception(message), errorCode_(errorCode) {}

    // CustomException에만 있는 멤버 함수
    int getErrorCode() const {
        return errorCode_;
    }

private:
    int errorCode_;
};

void throwException() {
    // CustomException 객체를 값으로 던짐 (복사본이 던져짐)
    CustomException ex("CustomException occurred", 404);
    throw ex;  // 함수 종료 시 스택에서 삭제될 객체의 복사본이 던져짐
}

int mainException() {
    try {
        throwException();
    }
    catch (Exception& e) { // Exception을 값으로 잡음 -> 객체 잘림 발생
        std::cout << e.what() << std::endl;

        // 파생 클래스의 멤버 접근 시도
        try {
            CustomException& ce = dynamic_cast<CustomException&>(e);
            std::cout << "Error code: " << ce.getErrorCode() << std::endl;
        }
        catch (std::bad_cast&) {
            // 객체 잘림으로 인해 CustomException으로 캐스팅 실패
            std::cout << "Caught bad_cast: Object slicing occurred, cannot cast to CustomException." << std::endl;
        }
    }

    return 0;
}