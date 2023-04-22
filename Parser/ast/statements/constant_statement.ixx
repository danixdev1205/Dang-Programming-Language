/**
 * Dang Programming Language Abstract Syntax constant declaration statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:constant_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST constant declaration statement component. */
    class constant_statement final : public statement
    {
    public:
        /**
         * Initializes new AST print statement.
         * @param expression Constant AST value expression.
         * @param identifier Constant identifier.
         * @param type Constant data type.
         */
        explicit constant_statement(const expression* const expression, const std::wstring& identifier,
                                    const std::wstring& type = L"auto")
            : value_(expression),
              type_(type),
              identifier_(identifier)
        {
        }


        /** AST print statement destructor. */
        ~constant_statement() override { delete value_; }

    private:
        /** Constant AST value expression. */
        const expression* const value_;

        /** Constant data type. */
        const std::wstring type_;

        /** Constant identifier. */
        const std::wstring identifier_;


        /** Outputs print statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            return os << "const " << type_ << " " << identifier_ << "=" << *value_ << ";";
        }
    };
}
