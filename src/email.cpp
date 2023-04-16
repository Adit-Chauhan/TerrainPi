#include "email.h"

EmailSender::EmailSender(const std::string& username, const std::string& password) :
        m_username(username),
        m_password(password) {}

void EmailSender::sendEmails(const std::string& subject, const std::string& body) {
    SMTPclient smtp;
    smtp.server = "smtp.gmail.com";
    smtp.port = 587;
    smtp.login = m_username;
    smtp.password = m_password;

    // Set email parameters
    for (auto to:recivers){
        smtp.from = m_username;
        smtp.to = to;
        smtp.subject = subject;
        smtp.message = body;

        // Send email
        if (smtp.send()) {
            std::cout << "Email sent successfully!" << std::endl;
        } else {
            std::cout << "Error sending email." << std::endl;
        }
    }
}

void EmailSender::new_friend(std::string newEmail){
    recivers.push_back(newEmail);
}

DrunkCallback::DrunkCallback(EmailSender* email) :
        m_sender(email){}

void DrunkCallback::send_email() {
    // Send email to friend
    std::string subject = "Driver is drunk";
    std::string body = "Please take appropriate action.";
    m_sender.sendEmails(subject, body);

    std::cout << "Drunk email sent to friend." << std::endl;
}

SleepyCallback::SleepyCallback(EmailSender *email) :
        m_sender(email) {}

void SleepyCallback::send_email() {
    // Send email to friend
    std::string subject = "Driver is drowsy";
    std::string body = "Please take appropriate action.";
    m_sender.sendEmails(subject, body);
    std::cout << "Drowsy email sent to friend." << std::endl;
}
