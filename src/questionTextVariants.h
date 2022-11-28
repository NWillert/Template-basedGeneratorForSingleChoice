#ifndef QUESTIONTEXTVARIANTS_H
#define QUESTIONTEXTVARIANTS_H



//Class for instantiating a question, with all necessary values. so that all questions can be stored at creation, and be later used to write the corresponding xmls
class QuestionTextVariants
{
public:
    QuestionTextVariants(int Id, std::string q_name, std::string q_author, std::string q_description, std::string q_additionalText, std::string q_code, std::string q_task,
        std::vector<std::string> q_correctAnswers, std::vector<std::string> q_wrongAnswers);

    int GetQuestionId();
    std::string GetName();
    std::string GetAuthor();
    std::string GetDescription();
    std::string GetCode();
    std::string GetAdditionalText();
    std::string GetTask();
    std::vector<std::string> GetCorrectAnswers();
    std::vector<std::string> GetWrongAnswers();
    bool IsCodeEmpty();
    bool IsAdditionalTextEmpty();
private:
    int questionId;
    std::string name{}, author{}, description{}, code{}, additionalText{}, task{};
    std::vector<std::string> correctAnswers;
    std::vector<std::string> wrongAnswers;
};

#endif 