<?php
return [
    'routingPatterns' => [
        '#^/re/(\d+)($|[/\?])#' => '/re/index/${1}${2}',

        '#^/p/(\d+)/(\d+)($|[/\?])#' => '/index/test/${1}/${2}${3}',
        // '/p/:qid/:aid' => '/index/test/:qid/:aid',
    ],
];
