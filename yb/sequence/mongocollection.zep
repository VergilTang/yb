namespace Yb\Sequence;

class MongoCollection implements SequenceInterface
{
    protected mongoCollection;

    public function __construct(var mongoCollection) -> void
    {
        let this->mongoCollection = mongoCollection;
    }

    public function getNextSequence(string name) -> long
    {
        var r, s;

        let r = this->mongoCollection->findAndModify([
            "_id": name
        ], [
            "$inc": [
                "sequence": 1
            ]
        ], null, [
            "upsert": true,
            "new": true
        ]);

        if unlikely typeof r != "array" || ! fetch s, r["sequence"] {
            throw new Exception("Cannot get next sequence of: " . name);
        }

        return (long) s;
    }

    public function restoreSequences(array sequences) -> void
    {
        var name, sequence, options;

        let options = [
            "upsert": true
        ];

        for name, sequence in sequences {
            this->mongoCollection->insert([
                "_id": (string) name
            ], [
                "$set": [
                    "sequence": (long) sequence
                ]
            ], options);
        }
    }

}
