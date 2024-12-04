#include <vector>
#include <list>

class MathReport
{
    public:
        // Default constructor.
        MathReport();
        // Add newQuestion into the vector of mathQuestions
        // and the response to check with the correct answer.
        // If the response is correct, increase numCorrectAnswer.
        // Otherwise, increase numWrongAnswers and also insert
        // newQuestion into errorList.
        void insert(MathOperations newQuestion, int response);
        // Return the value of numCorrectAnswers.
        int getNumOfCorrectAnswers() const;
        // Return the value of numWrongAnswers.
        int getNumOfWrongAnswers() const;
        // Generate a brief report.
        // If showAnswer is true, display questions solved with
        // correct answers
        // otherwise, display questions without answers.
        void generateReport(bool showAnswer) const;
        // Display the questions in errorList for additional practice,
        // collect
        // the user answer, and check if the answer is correct so that it
        // can be removed from the errorList.
        // This function should also print "Congratulations!" With a message
        // confirming a correct answer. When the answer is wrong, it should
        // indicate this without printing the right answer, and encourage
        // the user to keep practicing.
        // Return false if all questions in errorList have been corrected and
        // removed
        // otherwise return true (meaning errorList is not empty yet, and the
        // user needs more practice).
        bool needMorePractice();
    private:
        int numCorrectAnswers; // number of correctly answered questions
        int numWrongAnswers; // number of wrong answers
        vector<MathOperations> mathQuestions; // Sequence of questions.
        list<MathOperations> errorList; // Sequence of questions with wrong answers.
};