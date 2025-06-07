// File: window_system.cpp

#include <iostream>
#include <functional>
#include <string>

// Базовий клас компонентів
class Component {
public:
    virtual void draw() const = 0;
    virtual ~Component() = default;
};

// Клас заголовку
class Title : public Component {
private:
    std::string text;
public:
    explicit Title(const std::string& titleText) : text(titleText) {}

    void draw() const override {
        std::cout << "Title: " << text << std::endl;
    }
};

// Клас кнопки
class Button : public Component {
private:
    std::string label;
    std::function<void()> callback;
public:
    explicit Button(const std::string& labelText) : label(labelText) {}

    void setCallback(std::function<void()> cb) {
        callback = std::move(cb);
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

// Клас вікна
class Window {
private:
    Title title;
    Button button;

    void onButtonPressed() const {
        std::cout << "Window received button press!\n";
    }

public:
    Window(const std::string& windowTitle, const std::string& buttonText)
        : title(windowTitle), button(buttonText)
    {
        button.setCallback([this]() { this->onButtonPressed(); });
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

// Головна функція
int main() {
    Window myWindow("Main Window", "OK");
    myWindow.draw();

    std::cout << "\nSimulating key press:\n";
    myWindow.simulateKeyPress();

    return 0;
}
