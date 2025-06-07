#include <iostream>
#include <string>

class Component {
public:
    virtual void draw() const = 0;
    virtual ~Component() = default;
};

class Title : public Component {
private:
    std::string text;
public:
    explicit Title(const std::string& titleText) : text(titleText) {}

    void draw() const override {
        std::cout << "Title: " << text << std::endl;
    }
};

class Button : public Component {
private:
    std::string label;
    void (*callback)() = nullptr; // Вказівник на функцію без аргументів

public:
    explicit Button(const std::string& labelText) : label(labelText) {}

    void setCallback(void (*cb)()) {
        callback = cb;
    }

    void pressKey() const {
        if (callback) {
            callback();
        } else {
            std::cout << "No callback assigned to button.\n";
        }
    }

    void draw() const override {
        std::cout << "Button: " << label << std::endl;
    }
};

class Window {
private:
    Title title;
    Button button;

    static void onButtonPressedStatic() {
        std::cout << "Window received button press!\n";
    }

public:
    Window(const std::string& windowTitle, const std::string& buttonText)
        : title(windowTitle), button(buttonText)
    {
        button.setCallback(Window::onButtonPressedStatic);
    }

    void draw() const {
        std::cout << "Drawing window:\n";
        title.draw();
        button.draw();
    }

    void simulateKeyPress() const {
        button.pressKey();
    }
};

int main() {
    Window myWindow("Main Window", "OK");
    myWindow.draw();

    std::cout << "\nSimulating key press:\n";
    myWindow.simulateKeyPress();

    return 0;
}