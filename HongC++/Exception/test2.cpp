//#include <iostream>
//#include <string>
//
//// 사용자 정의 예외의 기본 클래스
//class Exception {
//public:
//    explicit Exception(const std::string& message) : message_(message) {}
//
//    // 가상 소멸자를 추가해 다형성 지원
//    virtual ~Exception() {}
//
//    // 예외 메시지를 반환하는 가상 함수
//    virtual const char* what() const noexcept {
//        return message_.c_str();
//    }
//
//private:
//    std::string message_;
//};
//
//// Exception을 상속받은 커스텀 예외 클래스
//class CustomException : public Exception {
//public:
//    explicit CustomException(const std::string& message, int errorCode)
//        : Exception(message), errorCode_(errorCode) {}
//
//    // CustomException에만 있는 멤버 함수
//    int getErrorCode() const {
//        return errorCode_;
//    }
//
//private:
//    int errorCode_;
//};
//
//void throwException() {
//    // 예외 객체를 동적으로 생성하여 포인터로 던짐 (메모리 관리 필요)
//    throw new CustomException("CustomException occurred", 404);
//}
//
//int main2() {
//    try {
//        throwException();
//    }
//    // 포인터로 던진 예외를 잡음
//    catch (Exception* e) {
//        std::cout << e->what() << std::endl;
//
//        // 파생 클래스로 dynamic_cast하여 멤버 접근 시도
//        if (CustomException* ce = dynamic_cast<CustomException*>(e)) {
//            std::cout << "Error code: " << ce->getErrorCode() << std::endl;
//        }
//        else {
//            std::cout << "Caught base Exception, cannot cast to CustomException." << std::endl;
//        }
//
//        // 동적으로 할당한 예외 객체 해제
//        delete e;
//    }
//
//    return 0;
//}
