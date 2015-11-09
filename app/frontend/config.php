<?php
return [
    'routingPatterns' => [
        '#^/p/(\d+)/(\d+)($|[/\?])#' => '/index/test/${1}/${2}${3}',
        // '/p/:qid/:aid' => '/index/test/:qid/:aid',
    ],
];
