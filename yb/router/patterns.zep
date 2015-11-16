namespace Yb\Router;

class Patterns
{
    const DEFAULT_TYPE = "\w+";

    protected types;
    protected matches;
    protected patterns;

    public function __construct(array types) -> void
    {
        let this->types = types;
    }

    public function getPatterns() -> array
    {
        if typeof this->patterns == "array" {
            return this->patterns;
        }

        return [];
    }

    public function aliases(array aliases, string prefix = "") -> void
    {
        var from, to;

        for from, to in aliases {
            this->alias(from, to, prefix);
        }
    }

    public function alias(string from, string to, string prefix = "") -> void
    {

        let this->matches = [];
        let from = (string) preg_replace_callback("#/\\{(\\w+)(\\:\\w+)?\\}#", [this, "replaceMatches"], from);

        if prefix->length() > 0 {
            let prefix = (string) preg_quote(prefix, "#");
        }

        let from = "#^" . prefix . from . "($|[/\?])#";
        let to = prefix . strtr(to, this->matches) . sprintf("${%d}", count(this->matches) + 1);

        let this->patterns[from] = to;
    }

    public function replaceMatches(array m) -> string
    {
        string t;
        var n, k, v;

        if unlikely ! fetch n, m[1] {
            throw new Exception("Invalid matches");
        }

        let n = "{" . n . "}";
        if unlikely isset this->matches[n] {
            throw new Exception("Duplicate match: " . n);
        }

        let this->matches[n] = sprintf("${%d}", count(this->matches) + 1);

        let t = self::DEFAULT_TYPE;
        if fetch k, m[2] {
            let k = substr((string) k, 1);
            if fetch v, this->types[k] {
                let t = (string) v;
            }
        }

        return "/(" . t . ")";
    }

}
