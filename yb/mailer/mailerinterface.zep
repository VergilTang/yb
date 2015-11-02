namespace Yb\Mailer;

interface MailerInterface
{
    public function sendMessageTo(array message, array to, array cc = [], array bcc = []) -> void;

}
