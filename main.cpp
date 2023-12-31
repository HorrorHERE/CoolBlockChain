#include <iostream>
#include <vector.>

namespace EventSystem
{
	class System
	{
	private:
		friend class Event;
		std::string name;
		int32_t descriptor;
		int16_t index;
		bool active;
		std::vector<Event*> events;
	public:
		System(std::string);
		~System();
		void addEvent(Event*);
		Event* getEvent();
		vool isActive();
	};

	class Event
	{
	public:
		enum DeviceType : int8_t
		{
			KEYBOARD = 1,
			MOUSE,
			TOUCHPAD,
			JOYSTICK
		};
		DeviceType dType;
		System* system = nullptr; //óêàçàòåëü íà ñèñòåìó, ÷òîáû ó Event áûëà èíôîðìàöèÿ î ñèñòåìå íà êîòîðîé îí âèñèò
	public:
		Event(DeviceType);
		DeviceType getdType();
		friend std::ostream& operator<<(std::ostream& stream, const DeviceType dType)
		{
			std::string result;
#define PRINT(a) result = #a; //stringify
			switch (dType)
			{
			case KEYBOARD: PRINT(KEYBOARD); break;
			case MOUSE: PRINT(MOUSE); break;
			case TOUCHPAD: PRINT(TOUCHPAD); break;
			case JOYSTICK: PRINT(JOYSTICK); break;
			}
			return stream << result;
		}
		void bind(System*, Event*);
	};

	class KeyboardEvent : public Event
	{
	private:
		int16_t keycode;
		bool pressed;
		bool released;
	public:
		KeyboardEvent(int16_t, bool, bool);
	};


	System::System(std::string name)
		:
		name(name),
		descriptor(132),
		index(1),
		active(True) {}

	System::~System()
	{

	}


	void System::addEvent(Event* e)
	{
		e->bind(this, e):
	}

	Event* System::getEvent()
	{
		return events.front();
	}

	bool System::isActive()
	{
		if (!system)
			return false;
		return true;
	}

	Event::Event(DeviceType dType)
	{
		this->dType = dType;
	}

	void Event::bind(System* system, Event* e)
	{
		this->system = system;
		this->system->events.push_back(e);
	}

	Event::DeviceType Event::getdType()
	{
		return this->dType;
	}

	KeyboardEvent:: KeyboardEvent(int16_t keycode, bool pressed, bool released)
		:
		Event(Event::KEYBOARD),
		keycode(keycode),
		pressed(pressed),
		released(released) {}

}

using namespace EventSystem;

int main(int argc, char argv[])
{
	System Foo("Foo");
	Event* e = new KeyboardEvent('a', true, false);

	(void)argc;
	(void)argv;
	return 0;
}
