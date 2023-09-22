#ifndef QUESTION_H
#define QUESTION_H



//Class for instantiating a question, with all necessary values. so that all questions can be stored at creation, and be later used to write the corresponding xmls
class Question
{
public:
    Question(const int& Id, const std::string& q_name, const std::string& q_author, const std::string& q_description, const std::string& q_additionalText, const std::string& q_code, const std::string& q_taxonomy, const std::string& q_task,
        const std::string& q_correctAnswer, const std::string& q_wrongAnswerOne, const std::string& q_wrongAnswerTwo, const std::string& q_wrongAnswerThree, const Picture& q_picture);

    int GetQuestionId();
    std::string GetName();
    std::string GetAuthor();
    std::string GetDescription();
    std::string GetCode();
    std::string GetAdditionalText();
    std::string GetTaxonomy();
    std::string GetTask();
    std::string GetCorrectAnswer();
    std::string GetWrongAnswerOne();
    std::string GetWrongAnswerTwo();
    std::string GetWrongAnswerThree();
    bool IsCodeEmpty();
    bool IsAdditionalTextEmpty();
    bool IsTaxonomyEmpty();
    Picture GetPicture();
private:
    int questionId;
    std::string name{}, author{}, description{}, code{}, additionalText{}, taxonomy{}, task{}, correctAnswer{}, wrongAnswerOne{}, wrongAnswerTwo{}, wrongAnswerThree{};
    Picture picture;
};

#endif 