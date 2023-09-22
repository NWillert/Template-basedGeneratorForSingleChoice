#include <string>
#include "picture.h"
#include "question.h"

using namespace std;
//Class for instantiating a question, with all necessary values. so that all questions can be stored at creation, and be later used to write the corresponding xmls

    Question::Question(const int& Id, const std::string& q_name, const std::string& q_author, const std::string& q_description, const std::string& q_additionalText, const std::string& q_code, const std::string& q_taxonomy, const std::string& q_task,
        const std::string& q_correctAnswer, const std::string& q_wrongAnswerOne, const std::string& q_wrongAnswerTwo, const std::string& q_wrongAnswerThree, const Picture& q_picture) {
        questionId = Id;
        name = q_name;
        author = q_author;
        description = q_description;
        additionalText = q_additionalText;
        code = q_code;
        taxonomy = q_taxonomy;
        task = q_task;
        correctAnswer = q_correctAnswer;
        wrongAnswerOne = q_wrongAnswerOne;
        wrongAnswerTwo = q_wrongAnswerTwo;
        wrongAnswerThree = q_wrongAnswerThree;
        picture = q_picture;
    }

    int Question::GetQuestionId() {
        return questionId;
    }
    string Question::GetName() {
        return name;
    }
    string Question::GetAuthor() {
        return author;
    }
    string Question::GetDescription() {
        return description;
    }
    string Question::GetCode() {
        return code;
    }
    string Question::GetAdditionalText() {
        return additionalText;
    }
    string Question::GetTaxonomy() {
        return taxonomy;
    }
    string Question::GetTask() {
        return task;
    }
    string Question::GetCorrectAnswer() {
        return correctAnswer;
    }
    string Question::GetWrongAnswerOne() {
        return wrongAnswerOne;
    }
    string Question::GetWrongAnswerTwo() {
        return wrongAnswerTwo;
    }
    string Question::GetWrongAnswerThree() {
        return wrongAnswerThree;
    }
    bool Question::IsCodeEmpty() {
        return code.empty();
    }
    bool Question::IsAdditionalTextEmpty() {
        return additionalText.empty();
    }
    bool Question::IsTaxonomyEmpty() {
        return taxonomy.empty();
    }
    Picture Question::GetPicture() {
        return picture;
    }
