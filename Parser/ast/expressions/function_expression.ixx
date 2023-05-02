/**
 * Dang Programming Language Abstract Syntax function expression component.
 * @author danixdev1205
 */
export module dang.ast.expressions:function_expression;


import "expression.hxx";
import std;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST function expression component. */
    class function_expression final : public expression
    {
    public:
        /**
         * Initializes new AST function expression.
         * @param identifier function identifier.
         */
        explicit function_expression(const std::wstring& identifier)
            : identifier_(identifier)
        {
        }

        explicit function_expression(const std::wstring& identifier, std::vector<const expression*> parameters,
                                     const std::wstring& type)
            : identifier_(identifier),
              type_(type),
              parameters_(parameters)
        {
        }

    private:
        const std::wstring identifier_, type_;

        std::vector<const expression*> parameters_;


        /** Outputs function expression to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            os << identifier_;

            if (!type_.empty())
                os << "<" << type_ << ">";
            
            os << "(";

            for (auto i = 0; i < parameters_.size(); i++)
            {
                os << *parameters_[i];

                if (i != parameters_.size() - 1)
                    os << ",";
            }

            return os << ")";
        }
    };
}
