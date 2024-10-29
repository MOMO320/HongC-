#include <iostream>

using namespace std;

// ���� ���

class USBDevice
{
private:
	long m_id;

public:
	USBDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void plugAndPlay() {}
};

class NetWorkDevice
{
private:
	long m_id;
public:
	NetWorkDevice(long id) : m_id(id) {}
	
	long getID() { return m_id; }

	void networking() {}
};

class USBNetWorkDevice : public USBDevice, public NetWorkDevice
{
public:
	USBNetWorkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetWorkDevice(net_id)
	{}
};

int main()
{
	USBNetWorkDevice my_device(3.154, 6.022);

	my_device.networking();
	my_device.plugAndPlay();

	// ���� ��ӽ� �ߺ��� �Լ��� ��� �Ʒ��� ���� ��� �Ѵ�.
	my_device.NetWorkDevice::getID();	
	my_device.USBDevice::getID();

	return 0;
}