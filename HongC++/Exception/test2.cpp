//#include <iostream>
//#include <string>
//
//// ����� ���� ������ �⺻ Ŭ����
//class Exception {
//public:
//    explicit Exception(const std::string& message) : message_(message) {}
//
//    // ���� �Ҹ��ڸ� �߰��� ������ ����
//    virtual ~Exception() {}
//
//    // ���� �޽����� ��ȯ�ϴ� ���� �Լ�
//    virtual const char* what() const noexcept {
//        return message_.c_str();
//    }
//
//private:
//    std::string message_;
//};
//
//// Exception�� ��ӹ��� Ŀ���� ���� Ŭ����
//class CustomException : public Exception {
//public:
//    explicit CustomException(const std::string& message, int errorCode)
//        : Exception(message), errorCode_(errorCode) {}
//
//    // CustomException���� �ִ� ��� �Լ�
//    int getErrorCode() const {
//        return errorCode_;
//    }
//
//private:
//    int errorCode_;
//};
//
//void throwException() {
//    // ���� ��ü�� �������� �����Ͽ� �����ͷ� ���� (�޸� ���� �ʿ�)
//    throw new CustomException("CustomException occurred", 404);
//}
//
//int main2() {
//    try {
//        throwException();
//    }
//    // �����ͷ� ���� ���ܸ� ����
//    catch (Exception* e) {
//        std::cout << e->what() << std::endl;
//
//        // �Ļ� Ŭ������ dynamic_cast�Ͽ� ��� ���� �õ�
//        if (CustomException* ce = dynamic_cast<CustomException*>(e)) {
//            std::cout << "Error code: " << ce->getErrorCode() << std::endl;
//        }
//        else {
//            std::cout << "Caught base Exception, cannot cast to CustomException." << std::endl;
//        }
//
//        // �������� �Ҵ��� ���� ��ü ����
//        delete e;
//    }
//
//    return 0;
//}
