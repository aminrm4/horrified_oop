# 👻 Horrified_Board_Game
# 🧩 State Design Pattern in C++

## 📖 Definition
The **State Pattern** is a behavioral design pattern that allows an object to alter its behavior when its internal state changes. It appears as if the object has changed its class.

---

## 🧠 Key Idea
Encapsulate state-specific behavior in separate classes. Avoid large `if-else` or `switch` statements that check for state.

---

## 📦 Structure

- **Context**: Maintains an instance of a `State` subclass.
- **State Interface**: Defines the interface for state-specific behavior.
- **Concrete States**: Implement behavior for a particular state.

```cpp
class State {
public:
    virtual void handle(Context* context) = 0;
    virtual ~State() = default;
};
```
![A beautiful sunrise](../../Desktop/OIP.jpeg)

