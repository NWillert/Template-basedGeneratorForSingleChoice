#include <string>
#include <vector>
#include "questionTextVariants.h"

using namespace std;
//Class for instantiating a question, with all necessary values. so that all questions can be stored at creation, and be later used to write the corresponding xmls



QuestionTextVariants::QuestionTextVariants(int Id, std::string q_name, std::string q_author, std::string q_description, 
    std::string q_additionalText, std::string q_code, std::string q_task, std::vector<std::string> q_correctAnswers, std::vector<std::string> q_wrongAnswers, std::string q_filename, std::vector<std::string> q_exclusions)
{
    questionId = Id;
    name = q_name;
    author = q_author;
    description = q_description;
    additionalText = q_additionalText;
    code = q_code;
    task = q_task;
    correctAnswers = q_correctAnswers;
    wrongAnswers = q_wrongAnswers;
    filename = q_filename;
    exclusions = q_exclusions;
}

int QuestionTextVariants::GetQuestionId() {
    return questionId;
}
string QuestionTextVariants::GetName() {
    return name;
}
string QuestionTextVariants::GetAuthor() {
    return author;
}
string QuestionTextVariants::GetDescription() {
    return description;
}
string QuestionTextVariants::GetCode() {
    return code;
}
string QuestionTextVariants::GetAdditionalText() {
    return additionalText;
}
string QuestionTextVariants::GetTask() {
    return task;
}
string QuestionTextVariants::GetFileName() {
    return filename;
}
vector<std::string> QuestionTextVariants::GetCorrectAnswers()
{
    return correctAnswers;
}
vector<std::string> QuestionTextVariants::GetWrongAnswers()
{
    return wrongAnswers;
}
vector<std::string> QuestionTextVariants::GetExclusionHolder()
{
    return exclusions;
}
bool QuestionTextVariants::IsCodeEmpty() {
    return code.empty();
}
bool QuestionTextVariants::IsAdditionalTextEmpty() {
    return additionalText.empty();
}


