namespace Yb\Sequence;

interface SequenceInterface
{
    public function getNextSequence(string name) -> long;
    public function restoreSequences(array sequences) -> void;

}
