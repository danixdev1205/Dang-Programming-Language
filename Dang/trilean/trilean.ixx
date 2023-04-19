/**
 * Three-value logic.
 * @author danixdev1205
 */
export module trilean;


import std;


export
/** Three-value (Kleene and Priest) logic variable. */
struct trilean final
{
    /** Three-value logic value. */
    enum struct trilean_value : signed char
    {
        /**
         * False.
         * @code -1 @endcode
         */
        FALSE = -1,

        /**
         * Unsure.
         * @code 0 @endcode
         */
        unsure = 0,

        /**
         * True.
         * @code 1 @endcode
         */
        TRUE = 1
    };


    using enum trilean_value;


    /** Initializes new trilean. */
    trilean() = default;

    /**
     * Initializes new trilean.
     * @param value Trilean value.
     */
    trilean(const trilean_value value)
        : value_(value)
    {
    }

    /**
     * Initializes new trilean.
     * @param value Bool value.
     */
    trilean(const bool value)
        : value_(value ? TRUE : FALSE)
    {
    }


    /**
     * Logical NOT for trilean.
     * @return Arithmetical opposite of the value.
     */
    trilean operator!() const { return static_cast<trilean_value>(-static_cast<char>(value_)); }

    /**
     * Logical AND for trilean.
     * @param other Other trilean.
     * @return Arithmetical minimum of the values.
     */
    bool operator==(const trilean other) const { return value_ == other.value_; }

    /**
     * Logical AND for trilean.
     * @param other Other trilean value.
     * @return Arithmetical minimum of the values.
     */
    bool operator==(const trilean_value other) const { return value_ == other; }

    /**
     * Logical AND for trilean.
     * @param other Other trilean.
     * @return Arithmetical minimum of the values.
     */
    trilean operator&&(const trilean other) const { return std::min(value_, other.value_); }

    /**
     * Logical OR for trilean.
     * @param other Other trilean.
     * @return Arithmetical maximum of the values.
     */
    trilean operator||(const trilean other) const { return std::max(value_, other.value_); }

    /**
     * Logical IMPLICATION for trilean.
     * @param other Other trilean.
     * @return Arithmetical maximum of own arithmetical opposite value and the other value.
     */
    trilean operator%(const trilean other) const
    {
        return std::max(static_cast<trilean_value>(-static_cast<char>(value_)), other.value_);
    }

    /**
     * Logical AND assignment operator.
     * @param other Other trilean.
     * @return Arithmetical minimum of the values.
     */
    trilean operator&=(const trilean other) const { return std::min(value_, other.value_); }

    /**
     * Logical OR assignment operator.
     * @param other Other trilean.
     * @return Arithmetical minimum of the values.
     */
    trilean operator|=(const trilean other) const { return std::max(value_, other.value_); }

    /**
     * Logical IMPLICATION assignment operator.
     * @param other Other trilean.
     * @return Arithmetical minimum of the values.
     */
    trilean operator%=(const trilean other) const
    {
        return std::max(static_cast<trilean_value>(-static_cast<char>(value_)), other.value_);
    }

    /**
     * Converts trilean to boolean.
     * @return Boolean value.
     */
    // ReSharper disable once CppNonExplicitConversionOperator
    operator bool() const { return value_ == TRUE; }

    /**
     * Trilean output stream.
     * @param os Output stream.
     * @param obj Trilean to output.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const trilean obj)
    {
        switch (obj.value_)
        {
        case TRUE:
            return os << "true";
        case FALSE:
            return os << "false";
        default:
            return os << "unsure";
        }
    }

    /**
     * Trilean wide character output stream.
     * @param os Wide character output stream.
     * @param obj Trilean to output.
     * @return Wide character output stream.
     */
    friend std::wostream& operator<<(std::wostream& os, const trilean obj)
    {
        switch (obj.value_)
        {
        case TRUE:
            return os << "true";
        case FALSE:
            return os << "false";
        default:
            return os << "unsure";
        }
    }

    /**
     * Trilean input stream.
     * @param is Input stream.
     * @param obj Trilean to input.
     * @return Input stream.
     */
    friend std::istream& operator>>(std::istream& is, trilean& obj)
    {
        char buf[7];
        is >> buf;

        if (std::strcmp(buf, "true") == 0)
            obj.value_ = TRUE;
        else if (std::strcmp(buf, "false") == 0)
            obj.value_ = FALSE;
        else
            obj.value_ = unsure;

        return is;
    }

    /**
     * Trilean wide character input stream.
     * @param is Wide character input stream.
     * @param obj Trilean to input.
     * @return Wide character input stream.
     */
    friend std::wistream& operator>>(std::wistream& is, trilean& obj)
    {
        wchar_t buf[7];
        is >> buf;

        if (std::wcscmp(buf, L"true") == 0)
            obj.value_ = TRUE;
        else if (std::wcscmp(buf, L"false") == 0)
            obj.value_ = FALSE;
        else
            obj.value_ = unsure;

        return is;
    }

private:
    /** Trilean value. */
    trilean_value value_;
};
