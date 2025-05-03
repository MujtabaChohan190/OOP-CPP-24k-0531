   const char* what() const noexcept override {
        return "Stack underflow: Attempted to pop or access top from an empty stack.";
    }
};
