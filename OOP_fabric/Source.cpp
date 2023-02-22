#include <iostream>
#include <memory>
#include <tuple>

class Button {
public:
	virtual ~Button(){}
	virtual void paint() = 0;

};

class MacButton : public Button {
	void paint() override {
		std::cout << "Paint MacButton\n";
	}

};

class WinButton : public Button {
	void paint() override {
		std::cout << "Paint WinButton\n";
	}

};

class Checkbox {
public:
	virtual void paint() = 0;
	virtual ~Checkbox(){}
};

class WinCheckBox : public Checkbox {
public:
	void paint() override {
		std::cout << "Paint WinCheckBox\n";
	}
};

class MacCheckBox : public Checkbox {
public:
	void paint() override {
		std::cout << "Paint MacCheckBox\n";
	}
};

class GUIFactory {
public:
	virtual std::shared_ptr<Button> createButton() = 0;
	virtual std::shared_ptr<Checkbox> createCheckbox() = 0;
	virtual ~GUIFactory(){}
};

class WinFactory : public GUIFactory {
public:
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<WinButton>();
	}
	std::shared_ptr<Checkbox> createCheckbox() override {
		return std::make_shared<WinCheckBox>();
	}
};

class MacFactory : public GUIFactory {
public:
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<MacButton>();
	}
	std::shared_ptr<Checkbox> createCheckbox() override {
		return std::make_shared<MacCheckBox>();
	}
};


class Application {
public:
	Application(std::shared_ptr<GUIFactory> factory) {
		_factory = factory;
	}
	void createUI() {
		_button = _factory->createButton();
		_checkbox = _factory->createCheckbox();
	}
	void paint() {
		_button->paint();
		_checkbox->paint();
	}

private:
	std::shared_ptr<GUIFactory> _factory;
	std::shared_ptr<Button> _button;
	std::shared_ptr<Checkbox> _checkbox;
};

int main() {

	/*std::string config;

	std::shared_ptr<GUIFactory> factory;
	std::cout << "Enter platform (Mac, Windows): ";
	std::cin >> config;

	if (config == "Mac") {
		factory = std::make_shared<MacFactory>();
	}
	else if (config == "Windows") {
		factory = std::make_shared <WinFactory>();
	}

	std::shared_ptr<Application> app = std::make_shared<Application>(factory);
	app->createUI();
	app->paint();*/

	std::tuple<int, float, std::string> t{ 5, 4.2f, "hello" };
	std::cout << std::get<0>(t);


}