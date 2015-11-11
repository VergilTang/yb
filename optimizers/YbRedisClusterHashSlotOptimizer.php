<?php

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilerException;
use Zephir\CompiledExpression;
use Zephir\CompilationContext;
use Zephir\Optimizers\OptimizerAbstract;

class YbRedisClusterHashSlotOptimizer extends OptimizerAbstract
{
    public function optimize(array $expression, Call $call, CompilationContext $context)
    {
        if (!isset($expression['parameters']) || count($expression['parameters']) != 1) {
            throw new CompilerException("'yb_redis_cluster_hash_slot' requires one parameter", $expression);
        }

        $call->processExpectedReturn($context);

        $symbolVariable = $call->getSymbolVariable();
        if (!$symbolVariable->isInt()) {
            throw new CompilerException("'yb_redis_cluster_hash_slot' return value can only be stored in int variables", $expression);
        }

        $resolvedParams = $call->getReadOnlyResolvedParams($expression['parameters'], $context, $expression);

        return new CompiledExpression('long', 'yb_redis_cluster_hash_slot( ' . $resolvedParams[0] . ')', $expression);
    }

}
