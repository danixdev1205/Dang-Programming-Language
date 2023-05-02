/**
* Dang Programming Language Abstract Syntax variable declaration statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:func_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST variable declaration statement component. */
    class func_statement final : public statement
    {
    public:
        /**
         * Initializes new AST print statement.
         * @param expression Variable AST value expression.
         * @param identifier Variable identifier.
         * @param type Variable data type.
         */
        explicit func_statement(const statement* const expression, const std::wstring& identifier,
                                std::vector<const statement*> parameters,
                                const std::wstring& type = L"void")
            : value_(expression),
              type_(type),
              identifier_(identifier),
              parameters_(parameters)
        {
        }


        /** AST print statement destructor. */
        ~func_statement() override { delete value_; }

    private:
        /** Variable AST value expression. */
        const statement* const value_;

        /** Variable data type. */
        const std::wstring type_;

        /** Variable identifier. */
        const std::wstring identifier_;

        std::vector<const statement*> parameters_;


        /** Outputs print statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            os << "auto " << identifier_ << "=[](";

            for (auto i = 0; i < parameters_.size(); i++)
            {
                os << *parameters_[i];

                if (i != parameters_.size() - 1)
                    os << ",";
            }

            return os << ")->" << type_ << "\n{" << *value_ << "};";
        }
    };
}
