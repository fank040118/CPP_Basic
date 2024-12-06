
#ifndef MathOperations_H
#define MathOperations_H

class MathOperations
{
    public:
        // Default constructor.
        MathOperations();
        // Set the private data members, operand1 and operand2,
        // to op1 and op2 respectively.
        void setOperands(int op1, int op2);
        // Return the value of the data member: theoperator.
        char getOperator() const;
        // Return the value of the data member: answer.
        int getAnswer() const;
        // 1. Set theoperator to '+'.
        // 2. Apply the addition operation to operand1 and operand2.
        // 3 Set the answer equal to operand1 + operand2.
        void Addition();
        // Set theoperator to '-'
        // Apply the subtraction operation to operand1 and operand2
        // Set the answer equal to operand1 - operand2.
        void Subtraction();
        // Set theoperator to 'x'
        // Apply the multiplication operation to operand1 and
        // operand2.
        // Set the answer equal to operand1 * operand2.
        void Multiplication();
        // Set theoperator to '÷' (obelus, in ASCII code character
        // 246).
        // Apply the integer division operation to operand1 and
        // operand2.
        // Set the answer equal to operand1 ÷ operand2.
        void Division();
        // If answer == response, it returns true.
        // Otherwise it returns false.
        bool checkAnswer(int response) const;
        // Display the question in the format described in the problem
        // statement.
        // For example:
        // 146
        // + 79
        // _____
        //
        void print() const;
        // Display the question by calling print() first.
        // Then ask the user for the answer.
        // Returns the valid user answer collected from the user
        // input.
        // In the case of invalid input, indicate this and
        // ask the user again.
        int collectUserAnswer() const;
    private:
        int operand1; // the first operand for basic math operation
        int operand2; // the second operand for basic math operation
        char theoperator; // the current operator;
        int answer; // the correct answer
};

#endif