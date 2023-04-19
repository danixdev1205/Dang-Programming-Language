import dang;
import dang.enums;
import std;


export
/** Dang Programming Language. */
namespace dang
{
    /** Interpreted element. */
    struct token final
    {
        using enum enums::token_type;

        
        /**
         * Initializes interpreted element.
         * @param type Interpreted element type.
         * @param value Interpreted element raw value.
         * @param position Interpreted element position in file.
         */
        [[nodiscard]]
        token(const enums::token_type type, std::wstring value, const std::pair<size_t, size_t>& position)
            : type_(type),
              value_(std::move(value)),
              position_(position)
        {
        }

        /**
         * Initializes interpreted element.
         * @param type Interpreted element type.
         * @param position Interpreted element position in file.
         */
        [[nodiscard]]
        token(const enums::token_type type, const std::pair<size_t, size_t>& position)
            : type_(type),
              position_(position)
        {
        }


        /**
         * Compares interpreted element and with an interpreted element type.
         * @param type Interpreted element type.
         * @return Whether interpreted element's type match the comparing type.
         */
        bool operator==(const enums::token_type type) const { return type_ == type; }

        /**
         * Compares interpreted element and with an interpreted element type.
         * @param type Interpreted element type.
         * @return Whether interpreted element's type do not match the comparing type.
         */
        bool operator!=(const enums::token_type type) const { return type_ != type; }


        /**
         * Print interpreted element to a wide character output stream.
         * @param os Wide character output stream.
         * @param obj Interpreted element.
         * @return Wide character output stream.
         */
        friend std::wostream& operator<<(std::wostream& os, const token& obj)
        {
            if (obj.value().empty())
                return os << to_wstring(obj.type_);

            return os << obj.value();
        }


        /**
         * Interpreted element type getter.
         * @return Interpreted element type.
         */
        [[nodiscard, maybe_unused]]
        enums::token_type type() const { return type_; }

        /**
         * Interpreted element raw value getter.
         * @return Interpreted element raw value.
         */
        [[nodiscard, maybe_unused]]
        std::wstring value() const { return value_; }

        /**
         * Interpreted element line getter.
         * @return Interpreted element line.
         */
        [[nodiscard, maybe_unused]]
        size_t line() const { return position_.first; }

        /**
         * Interpreted element column getter.
         * @return Interpreted element column.
         */
        [[nodiscard, maybe_unused]]
        size_t column() const { return position_.second; }


#pragma region Reading

        /**
         * Read interpreted element's value.
         * @tparam T Dang data type.
         * @return Interpreted element's value.
         */
        template <typename T>
        [[nodiscard]]
        T read() const
        {
            throw;
        }

        /**
         * Read interpreted element's value as a Dang boolean.
         * @return Interpreted element's Dang boolean value.
         */
        template <>
        [[nodiscard]]
        boolean read() const
        {
            if (type_ == literal_logical_true)
                return true;
            if (type_ == literal_logical_false)
                return false;

            throw;
        }

        /**
         * Read interpreted element's value as a Dang trilean.
         * @return Interpreted element's Dang trilean value.
         */
        template <>
        [[nodiscard]]
        trilean read() const
        {
            if (type_ == literal_logical_true)
                return tri_true;
            if (type_ == literal_logical_unsure)
                return tri_unsure;
            if (type_ == literal_logical_false)
                return tri_false;

            throw;
        }

        /**
         * Read interpreted element's value as a Dang integer.
         * @return Interpreted element's Dang integer value.
         */
        template <>
        [[nodiscard]]
        integer read() const try
        {
            if (type_ != literal_integer)
                throw;

            if (value_.empty())
                throw;

            return std::stoll(value_);
        }
        catch (const std::invalid_argument&)
        {
            throw;
        }
        catch (const std::out_of_range&)
        {
            throw;
        }

        /**
         * Read interpreted element's value as a Dang decimal.
         * @return Interpreted element's Dang decimal value.
         */
        template <>
        [[nodiscard]]
        decimal read() const try
        {
            if (type_ != literal_decimal)
                throw;

            if (value_.empty())
                throw;

            return std::stod(value_);
        }
        catch (const std::invalid_argument&)
        {
            throw;
        }
        catch (const std::out_of_range&)
        {
            throw;
        }

        /**
         * Read interpreted element's value as a Dang symbol.
         * @return Interpreted element's Dang symbol value.
         */
        template <>
        [[nodiscard]]
        symbol read() const
        {
            if (type_ != literal_symbol)
                throw;

            if (value_.empty())
                throw;

            return value_[0];
        }

        /**
         * Read interpreted element's value as a Dang string.
         * @return Interpreted element's Dang string value.
         */
        template <>
        [[nodiscard]]
        string read() const
        {
            if (type_ != literal_string)
                throw;

            return value_;
        }

#pragma endregion

    private:
        /** Interpreted element type. */
        const enums::token_type type_;

        /** Interpreted element raw value. */
        [[maybe_unused]]
        const std::wstring value_;

        /** Interpreted element position in file. */
        const std::pair<size_t, size_t> position_;
    };
}
