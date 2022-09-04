<html>
	<body>
		<b>Algorithms defined in <code>&lt;algorithm&gt;</code><br><br> Source: <a href="https://en.cppreference.com/w/cpp/algorithm">https://en.cppreference.com</a></b>
		<br><br>
		<table class="t-dsc-begin">
			<tbody>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Non-modifying_sequence_operations">  Non-modifying sequence operations </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/all_any_none_of" title="cpp/algorithm/all any none of"> <span class="t-lines"><span>all_of</span><span>any_of</span><span>none_of</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   checks if a predicate is <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw2">true</span></span></span> for all, any or none of the elements in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_all_any_none_of&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/all_any_none_of" title="cpp/algorithm/ranges/all any none of"> <span class="t-lines"><span>ranges::all_of</span><span>ranges::any_of</span><span>ranges::none_of</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   checks if a predicate is <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw2">true</span></span></span> for all, any or none of the elements in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_all_any_none_of&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/for_each" title="cpp/algorithm/for each"> <span class="t-lines"><span>for_each</span></span></a></div>
						</div>
					</td>
					<td>   applies a function to a range of elements <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_for_each&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/for_each" title="cpp/algorithm/ranges/for each"> <span class="t-lines"><span>ranges::for_each</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   applies a function to a range of elements <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_for_each&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/for_each_n" title="cpp/algorithm/for each n"> <span class="t-lines"><span>for_each_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   applies a function object to the first n elements of a sequence  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_for_each_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/for_each_n" title="cpp/algorithm/ranges/for each n"> <span class="t-lines"><span>ranges::for_each_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   applies a function object to the first n elements of a sequence  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_for_each_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/count" title="cpp/algorithm/count"> <span class="t-lines"><span>count</span><span>count_if</span></span></a></div>
						</div>
					</td>
					<td>   returns the number of elements satisfying specific criteria  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_count&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/count" title="cpp/algorithm/ranges/count"> <span class="t-lines"><span>ranges::count</span><span>ranges::count_if</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns the number of elements satisfying specific criteria  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_count&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/mismatch" title="cpp/algorithm/mismatch"> <span class="t-lines"><span>mismatch</span></span></a></div>
						</div>
					</td>
					<td>   finds the first position where two ranges differ  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_mismatch&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/mismatch" title="cpp/algorithm/ranges/mismatch"> <span class="t-lines"><span>ranges::mismatch</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   finds the first position where two ranges differ  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_mismatch&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/find" title="cpp/algorithm/find"> <span class="t-lines"><span>find</span><span>find_if</span><span>find_if_not</span></span></a></div>
							<div><span class="t-lines"><span></span><span></span><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   finds the first element satisfying specific criteria  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_find&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/find" title="cpp/algorithm/ranges/find"> <span class="t-lines"><span>ranges::find</span><span>ranges::find_if</span><span>ranges::find_if_not</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   finds the first element satisfying specific criteria <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_find&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/find_last" title="cpp/algorithm/ranges/find last"> <span class="t-lines"><span>ranges::find_last</span><span>ranges::find_last_if</span><span>ranges::find_last_if_not</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx23">(C++23)</span></span><span><span class="t-mark-rev t-since-cxx23">(C++23)</span></span><span><span class="t-mark-rev t-since-cxx23">(C++23)</span></span></span></div>
						</div>
					</td>
					<td>   finds the last element satisfying specific criteria <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_find_last&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/find_end" title="cpp/algorithm/find end"> <span class="t-lines"><span>find_end</span></span></a></div>
						</div>
					</td>
					<td>   finds the last sequence of elements in a certain range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_find_end&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/find_end" title="cpp/algorithm/ranges/find end"> <span class="t-lines"><span>ranges::find_end</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   finds the last sequence of elements in a certain range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_find_end&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/find_first_of" title="cpp/algorithm/find first of"> <span class="t-lines"><span>find_first_of</span></span></a></div>
						</div>
					</td>
					<td>   searches for any one of a set of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_find_first_of&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/find_first_of" title="cpp/algorithm/ranges/find first of"> <span class="t-lines"><span>ranges::find_first_of</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   searches for any one of a set of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_find_first_of&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/adjacent_find" title="cpp/algorithm/adjacent find"> <span class="t-lines"><span>adjacent_find</span></span></a></div>
						</div>
					</td>
					<td>   finds the first two adjacent items that are equal (or satisfy a given predicate)  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_adjacent_find&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/adjacent_find" title="cpp/algorithm/ranges/adjacent find"> <span class="t-lines"><span>ranges::adjacent_find</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   finds the first two adjacent items that are equal (or satisfy a given predicate)  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_adjacent_find&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/search" title="cpp/algorithm/search"> <span class="t-lines"><span>search</span></span></a></div>
						</div>
					</td>
					<td>   searches for a range of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_search&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/search" title="cpp/algorithm/ranges/search"> <span class="t-lines"><span>ranges::search</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   searches for a range of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_search&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/search_n" title="cpp/algorithm/search n"> <span class="t-lines"><span>search_n</span></span></a></div>
						</div>
					</td>
					<td>   searches a range for a number of consecutive copies of an element  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_search_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/search_n" title="cpp/algorithm/ranges/search n"> <span class="t-lines"><span>ranges::search_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   searches for a number consecutive copies of an element in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_search_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/starts_with" title="cpp/algorithm/ranges/starts with"> <span class="t-lines"><span>ranges::starts_with</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx23">(C++23)</span></span></span></div>
						</div>
					</td>
					<td>   checks whether a range starts with another range <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_starts_with&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/ends_with" title="cpp/algorithm/ranges/ends with"> <span class="t-lines"><span>ranges::ends_with</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx23">(C++23)</span></span></span></div>
						</div>
					</td>
					<td>   checks whether a range ends with another range <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_ends_with&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Modifying_sequence_operations">  Modifying sequence operations </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/copy" title="cpp/algorithm/copy"> <span class="t-lines"><span>copy</span><span>copy_if</span></span></a></div>
							<div><span class="t-lines"><span></span><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   copies a range of elements to a new location  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/copy" title="cpp/algorithm/ranges/copy"> <span class="t-lines"><span>ranges::copy</span><span>ranges::copy_if</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies a range of elements to a new location  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/copy_n" title="cpp/algorithm/copy n"> <span class="t-lines"><span>copy_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   copies a number of elements to a new location  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_copy_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/copy_n" title="cpp/algorithm/ranges/copy n"> <span class="t-lines"><span>ranges::copy_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies a number of elements to a new location   <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_copy_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/copy_backward" title="cpp/algorithm/copy backward"> <span class="t-lines"><span>copy_backward</span></span></a></div>
						</div>
					</td>
					<td>   copies a range of elements in backwards order  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_copy_backward&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/copy_backward" title="cpp/algorithm/ranges/copy backward"> <span class="t-lines"><span>ranges::copy_backward</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies a range of elements in backwards order  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_copy_backward&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/move" title="cpp/algorithm/move"> <span class="t-lines"><span>move</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   moves a range of elements to a new location  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_move&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/move" title="cpp/algorithm/ranges/move"> <span class="t-lines"><span>ranges::move</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   moves a range of elements to a new location   <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_move&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/move_backward" title="cpp/algorithm/move backward"> <span class="t-lines"><span>move_backward</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   moves a range of elements to a new location in backwards order  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_move_backward&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/move_backward" title="cpp/algorithm/ranges/move backward"> <span class="t-lines"><span>ranges::move_backward</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   moves a range of elements to a new location in backwards order <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_move_backward&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/fill" title="cpp/algorithm/fill"> <span class="t-lines"><span>fill</span></span></a></div>
						</div>
					</td>
					<td>   copy-assigns the given value to every element in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_fill&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/fill" title="cpp/algorithm/ranges/fill"> <span class="t-lines"><span>ranges::fill</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   assigns a range of elements a certain value  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_fill&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/fill_n" title="cpp/algorithm/fill n"> <span class="t-lines"><span>fill_n</span></span></a></div>
						</div>
					</td>
					<td>   copy-assigns the given value to N elements in a range <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_fill_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/fill_n" title="cpp/algorithm/ranges/fill n"> <span class="t-lines"><span>ranges::fill_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   assigns a value to a number of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_fill_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/transform" title="cpp/algorithm/transform"> <span class="t-lines"><span>transform</span></span></a></div>
						</div>
					</td>
					<td>   applies a function to a range of elements, storing results in a destination range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_transform&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/transform" title="cpp/algorithm/ranges/transform"> <span class="t-lines"><span>ranges::transform</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   applies a function to a range of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_transform&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/generate" title="cpp/algorithm/generate"> <span class="t-lines"><span>generate</span></span></a></div>
						</div>
					</td>
					<td>   assigns the results of successive function calls to every element in a range <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_generate&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/generate" title="cpp/algorithm/ranges/generate"> <span class="t-lines"><span>ranges::generate</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   saves the result of a function in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_generate&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/generate_n" title="cpp/algorithm/generate n"> <span class="t-lines"><span>generate_n</span></span></a></div>
						</div>
					</td>
					<td>   assigns the results of successive function calls to N elements in a range <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_generate_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/generate_n" title="cpp/algorithm/ranges/generate n"> <span class="t-lines"><span>ranges::generate_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   saves the result of N applications of a function  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_generate_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/remove" title="cpp/algorithm/remove"> <span class="t-lines"><span>remove</span><span>remove_if</span></span></a></div>
						</div>
					</td>
					<td>   removes elements satisfying specific criteria  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_remove&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/remove" title="cpp/algorithm/ranges/remove"> <span class="t-lines"><span>ranges::remove</span><span>ranges::remove_if</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   removes elements satisfying specific criteria  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_remove&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/remove_copy" title="cpp/algorithm/remove copy"> <span class="t-lines"><span>remove_copy</span><span>remove_copy_if</span></span></a></div>
						</div>
					</td>
					<td>   copies a range of elements omitting those that satisfy specific criteria  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_remove_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/remove_copy" title="cpp/algorithm/ranges/remove copy"> <span class="t-lines"><span>ranges::remove_copy</span><span>ranges::remove_copy_if</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies a range of elements omitting those that satisfy specific criteria  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_remove_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/replace" title="cpp/algorithm/replace"> <span class="t-lines"><span>replace</span><span>replace_if</span></span></a></div>
						</div>
					</td>
					<td>   replaces all values satisfying specific criteria with another value  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_replace&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/replace" title="cpp/algorithm/ranges/replace"> <span class="t-lines"><span>ranges::replace</span><span>ranges::replace_if</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   replaces all values satisfying specific criteria with another value  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_replace&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/replace_copy" title="cpp/algorithm/replace copy"> <span class="t-lines"><span>replace_copy</span><span>replace_copy_if</span></span></a></div>
						</div>
					</td>
					<td>   copies a range, replacing elements satisfying specific criteria with another value  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_replace_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/replace_copy" title="cpp/algorithm/ranges/replace copy"> <span class="t-lines"><span>ranges::replace_copy</span><span>ranges::replace_copy_if</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies a range, replacing elements satisfying specific criteria with another value  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_replace_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/swap" title="cpp/algorithm/swap"> <span class="t-lines"><span>swap</span></span></a></div>
						</div>
					</td>
					<td>   swaps the values of two objects  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_swap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/swap_ranges" title="cpp/algorithm/swap ranges"> <span class="t-lines"><span>swap_ranges</span></span></a></div>
						</div>
					</td>
					<td>   swaps two ranges of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_swap_ranges&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/swap_ranges" title="cpp/algorithm/ranges/swap ranges"> <span class="t-lines"><span>ranges::swap_ranges</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   swaps two ranges of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_swap_ranges&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/iter_swap" title="cpp/algorithm/iter swap"> <span class="t-lines"><span>iter_swap</span></span></a></div>
						</div>
					</td>
					<td>   swaps the elements pointed to by two iterators  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_iter_swap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/reverse" title="cpp/algorithm/reverse"> <span class="t-lines"><span>reverse</span></span></a></div>
						</div>
					</td>
					<td>   reverses the order of elements in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_reverse&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/reverse" title="cpp/algorithm/ranges/reverse"> <span class="t-lines"><span>ranges::reverse</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   reverses the order of elements in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_reverse&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/reverse_copy" title="cpp/algorithm/reverse copy"> <span class="t-lines"><span>reverse_copy</span></span></a></div>
						</div>
					</td>
					<td>   creates a copy of a range that is reversed  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_reverse_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/reverse_copy" title="cpp/algorithm/ranges/reverse copy"> <span class="t-lines"><span>ranges::reverse_copy</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   creates a copy of a range that is reversed  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_reverse_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/rotate" title="cpp/algorithm/rotate"> <span class="t-lines"><span>rotate</span></span></a></div>
						</div>
					</td>
					<td>   rotates the order of elements in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_rotate&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/rotate" title="cpp/algorithm/ranges/rotate"> <span class="t-lines"><span>ranges::rotate</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   rotates the order of elements in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_rotate&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/rotate_copy" title="cpp/algorithm/rotate copy"> <span class="t-lines"><span>rotate_copy</span></span></a></div>
						</div>
					</td>
					<td>   copies and rotate a range of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_rotate_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/rotate_copy" title="cpp/algorithm/ranges/rotate copy"> <span class="t-lines"><span>ranges::rotate_copy</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies and rotate a range of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_rotate_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/shift" title="cpp/algorithm/shift"> <span class="t-lines"><span>shift_left</span><span>shift_right</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   shifts elements in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_shift&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/shift" title="cpp/algorithm/ranges/shift"> <span class="t-lines"><span>ranges::shift_left</span><span>ranges::shift_right</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx23">(C++23)</span></span></span></div>
						</div>
					</td>
					<td>   shifts elements in a range <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_shift&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/random_shuffle" title="cpp/algorithm/random shuffle"> <span class="t-lines"><span>random_shuffle</span><span>shuffle</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-until-cxx17">(until C++17)</span></span><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   randomly re-orders elements in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_random_shuffle&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/shuffle" title="cpp/algorithm/ranges/shuffle"> <span class="t-lines"><span>ranges::shuffle</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   randomly re-orders elements in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_shuffle&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/sample" title="cpp/algorithm/sample"> <span class="t-lines"><span>sample</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   selects n random elements from a sequence <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_sample&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/sample" title="cpp/algorithm/ranges/sample"> <span class="t-lines"><span>ranges::sample</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   selects n random elements from a sequence <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_sample&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/unique" title="cpp/algorithm/unique"> <span class="t-lines"><span>unique</span></span></a></div>
						</div>
					</td>
					<td>   removes consecutive duplicate elements in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_unique&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/unique" title="cpp/algorithm/ranges/unique"> <span class="t-lines"><span>ranges::unique</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   removes consecutive duplicate elements in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_unique&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/unique_copy" title="cpp/algorithm/unique copy"> <span class="t-lines"><span>unique_copy</span></span></a></div>
						</div>
					</td>
					<td>   creates a copy of some range of elements that contains no consecutive duplicates  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_unique_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/unique_copy" title="cpp/algorithm/ranges/unique copy"> <span class="t-lines"><span>ranges::unique_copy</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   creates a copy of some range of elements that contains no consecutive duplicates  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_unique_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Partitioning_operations">  Partitioning operations </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/is_partitioned" title="cpp/algorithm/is partitioned"> <span class="t-lines"><span>is_partitioned</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   determines if the range is partitioned by the given predicate  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_is_partitioned&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/is_partitioned" title="cpp/algorithm/ranges/is partitioned"> <span class="t-lines"><span>ranges::is_partitioned</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   determines if the range is partitioned by the given predicate   <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_is_partitioned&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/partition" title="cpp/algorithm/partition"> <span class="t-lines"><span>partition</span></span></a></div>
						</div>
					</td>
					<td>   divides a range of elements into two groups  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_partition&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/partition" title="cpp/algorithm/ranges/partition"> <span class="t-lines"><span>ranges::partition</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   divides a range of elements into two groups  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_partition&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/partition_copy" title="cpp/algorithm/partition copy"> <span class="t-lines"><span>partition_copy</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   copies a range dividing the elements into two groups  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_partition_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/partition_copy" title="cpp/algorithm/ranges/partition copy"> <span class="t-lines"><span>ranges::partition_copy</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies a range dividing the elements into two groups  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_partition_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/stable_partition" title="cpp/algorithm/stable partition"> <span class="t-lines"><span>stable_partition</span></span></a></div>
						</div>
					</td>
					<td>   divides elements into two groups while preserving their relative order  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_stable_partition&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/stable_partition" title="cpp/algorithm/ranges/stable partition"> <span class="t-lines"><span>ranges::stable_partition</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   divides elements into two groups while preserving their relative order  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_stable_partition&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/partition_point" title="cpp/algorithm/partition point"> <span class="t-lines"><span>partition_point</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   locates the partition point of a partitioned range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_partition_point&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/partition_point" title="cpp/algorithm/ranges/partition point"> <span class="t-lines"><span>ranges::partition_point</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   locates the partition point of a partitioned range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_partition_point&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Sorting_operations">  Sorting operations </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/is_sorted" title="cpp/algorithm/is sorted"> <span class="t-lines"><span>is_sorted</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   checks whether a range is sorted into ascending order  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_is_sorted&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/is_sorted" title="cpp/algorithm/ranges/is sorted"> <span class="t-lines"><span>ranges::is_sorted</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   checks whether a range is sorted into ascending order  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_is_sorted&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/is_sorted_until" title="cpp/algorithm/is sorted until"> <span class="t-lines"><span>is_sorted_until</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   finds the largest sorted subrange  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_is_sorted_until&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/is_sorted_until" title="cpp/algorithm/ranges/is sorted until"> <span class="t-lines"><span>ranges::is_sorted_until</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   finds the largest sorted subrange  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_is_sorted_until&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/sort" title="cpp/algorithm/sort"> <span class="t-lines"><span>sort</span></span></a></div>
						</div>
					</td>
					<td>   sorts a range into ascending order  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_sort&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/sort" title="cpp/algorithm/ranges/sort"> <span class="t-lines"><span>ranges::sort</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   sorts a range into ascending order  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_sort&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/partial_sort" title="cpp/algorithm/partial sort"> <span class="t-lines"><span>partial_sort</span></span></a></div>
						</div>
					</td>
					<td>   sorts the first N elements of a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_partial_sort&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/partial_sort" title="cpp/algorithm/ranges/partial sort"> <span class="t-lines"><span>ranges::partial_sort</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   sorts the first N elements of a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_partial_sort&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/partial_sort_copy" title="cpp/algorithm/partial sort copy"> <span class="t-lines"><span>partial_sort_copy</span></span></a></div>
						</div>
					</td>
					<td>   copies and partially sorts a range of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_partial_sort_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/partial_sort_copy" title="cpp/algorithm/ranges/partial sort copy"> <span class="t-lines"><span>ranges::partial_sort_copy</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies and partially sorts a range of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_partial_sort_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/stable_sort" title="cpp/algorithm/stable sort"> <span class="t-lines"><span>stable_sort</span></span></a></div>
						</div>
					</td>
					<td>   sorts a range of elements while preserving order between equal elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_stable_sort&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/stable_sort" title="cpp/algorithm/ranges/stable sort"> <span class="t-lines"><span>ranges::stable_sort</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   sorts a range of elements while preserving order between equal elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_stable_sort&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/nth_element" title="cpp/algorithm/nth element"> <span class="t-lines"><span>nth_element</span></span></a></div>
						</div>
					</td>
					<td>   partially sorts the given range making sure that it is partitioned by the given element  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_nth_element&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/nth_element" title="cpp/algorithm/ranges/nth element"> <span class="t-lines"><span>ranges::nth_element</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   partially sorts the given range making sure that it is partitioned by the given element  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_nth_element&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Binary_search_operations_.28on_sorted_ranges.29">  Binary search operations (on sorted ranges) </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/lower_bound" title="cpp/algorithm/lower bound"> <span class="t-lines"><span>lower_bound</span></span></a></div>
						</div>
					</td>
					<td>   returns an iterator to the first element <i>not less</i> than the given value <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_lower_bound&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/lower_bound" title="cpp/algorithm/ranges/lower bound"> <span class="t-lines"><span>ranges::lower_bound</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns an iterator to the first element <i>not less</i> than the given value <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_lower_bound&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/upper_bound" title="cpp/algorithm/upper bound"> <span class="t-lines"><span>upper_bound</span></span></a></div>
						</div>
					</td>
					<td>   returns an iterator to the first element <i>greater</i> than a certain value <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_upper_bound&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/upper_bound" title="cpp/algorithm/ranges/upper bound"> <span class="t-lines"><span>ranges::upper_bound</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns an iterator to the first element <i>greater</i> than a certain value <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_upper_bound&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/binary_search" title="cpp/algorithm/binary search"> <span class="t-lines"><span>binary_search</span></span></a></div>
						</div>
					</td>
					<td>   determines if an element exists in a partially-ordered range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_binary_search&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/binary_search" title="cpp/algorithm/ranges/binary search"> <span class="t-lines"><span>ranges::binary_search</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   determines if an element exists in a partially-ordered range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_binary_search&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/equal_range" title="cpp/algorithm/equal range"> <span class="t-lines"><span>equal_range</span></span></a></div>
						</div>
					</td>
					<td>   returns range of elements matching a specific key <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_equal_range&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/equal_range" title="cpp/algorithm/ranges/equal range"> <span class="t-lines"><span>ranges::equal_range</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns range of elements matching a specific key <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_equal_range&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Other_operations_on_sorted_ranges">  Other operations on sorted ranges </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/merge" title="cpp/algorithm/merge"> <span class="t-lines"><span>merge</span></span></a></div>
						</div>
					</td>
					<td>   merges two sorted ranges  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_merge&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/merge" title="cpp/algorithm/ranges/merge"> <span class="t-lines"><span>ranges::merge</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   merges two sorted ranges  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_merge&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/inplace_merge" title="cpp/algorithm/inplace merge"> <span class="t-lines"><span>inplace_merge</span></span></a></div>
						</div>
					</td>
					<td>   merges two ordered ranges in-place  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_inplace_merge&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/inplace_merge" title="cpp/algorithm/ranges/inplace merge"> <span class="t-lines"><span>ranges::inplace_merge</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   merges two ordered ranges in-place  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_inplace_merge&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Set_operations_.28on_sorted_ranges.29">  Set operations (on sorted ranges) </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/includes" title="cpp/algorithm/includes"> <span class="t-lines"><span>includes</span></span></a></div>
						</div>
					</td>
					<td>   returns true if one sequence is a subsequence of another  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_includes&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/includes" title="cpp/algorithm/ranges/includes"> <span class="t-lines"><span>ranges::includes</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns true if one sequence is a subsequence of another  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_includes&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/set_difference" title="cpp/algorithm/set difference"> <span class="t-lines"><span>set_difference</span></span></a></div>
						</div>
					</td>
					<td>   computes the difference between two sets  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_set_difference&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/set_difference" title="cpp/algorithm/ranges/set difference"> <span class="t-lines"><span>ranges::set_difference</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   computes the difference between two sets  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_set_difference&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/set_intersection" title="cpp/algorithm/set intersection"> <span class="t-lines"><span>set_intersection</span></span></a></div>
						</div>
					</td>
					<td>   computes the intersection of two sets  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_set_intersection&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/set_intersection" title="cpp/algorithm/ranges/set intersection"> <span class="t-lines"><span>ranges::set_intersection</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   computes the intersection of two sets  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_set_intersection&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/set_symmetric_difference" title="cpp/algorithm/set symmetric difference"> <span class="t-lines"><span>set_symmetric_difference</span></span></a></div>
						</div>
					</td>
					<td>   computes the symmetric difference between two sets  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_set_symmetric_difference&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/set_symmetric_difference" title="cpp/algorithm/ranges/set symmetric difference"> <span class="t-lines"><span>ranges::set_symmetric_difference</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   computes the symmetric difference between two sets  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_set_symmetric_difference&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/set_union" title="cpp/algorithm/set union"> <span class="t-lines"><span>set_union</span></span></a></div>
						</div>
					</td>
					<td>   computes the union of two sets  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_set_union&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/set_union" title="cpp/algorithm/ranges/set union"> <span class="t-lines"><span>ranges::set_union</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   computes the union of two sets  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_set_union&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Heap_operations">  Heap operations </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/is_heap" title="cpp/algorithm/is heap"> <span class="t-lines"><span>is_heap</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   checks if the given range is a max heap <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_is_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/is_heap" title="cpp/algorithm/ranges/is heap"> <span class="t-lines"><span>ranges::is_heap</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   checks if the given range is a max heap <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_is_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/is_heap_until" title="cpp/algorithm/is heap until"> <span class="t-lines"><span>is_heap_until</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   finds the largest subrange that is a max heap  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_is_heap_until&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/is_heap_until" title="cpp/algorithm/ranges/is heap until"> <span class="t-lines"><span>ranges::is_heap_until</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   finds the largest subrange that is a max heap  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_is_heap_until&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/make_heap" title="cpp/algorithm/make heap"> <span class="t-lines"><span>make_heap</span></span></a></div>
						</div>
					</td>
					<td>   creates a max heap out of a range of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_make_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/make_heap" title="cpp/algorithm/ranges/make heap"> <span class="t-lines"><span>ranges::make_heap</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   creates a max heap out of a range of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_make_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/push_heap" title="cpp/algorithm/push heap"> <span class="t-lines"><span>push_heap</span></span></a></div>
						</div>
					</td>
					<td>   adds an element to a max heap  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_push_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/push_heap" title="cpp/algorithm/ranges/push heap"> <span class="t-lines"><span>ranges::push_heap</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   adds an element to a max heap  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_push_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/pop_heap" title="cpp/algorithm/pop heap"> <span class="t-lines"><span>pop_heap</span></span></a></div>
						</div>
					</td>
					<td>   removes the largest element from a max heap  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_pop_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/pop_heap" title="cpp/algorithm/ranges/pop heap"> <span class="t-lines"><span>ranges::pop_heap</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   removes the largest element from a max heap  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_pop_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/sort_heap" title="cpp/algorithm/sort heap"> <span class="t-lines"><span>sort_heap</span></span></a></div>
						</div>
					</td>
					<td>   turns a max heap into a range of elements sorted in ascending order  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_sort_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/sort_heap" title="cpp/algorithm/ranges/sort heap"> <span class="t-lines"><span>ranges::sort_heap</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   turns a max heap into a range of elements sorted in ascending order  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_sort_heap&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Minimum.2Fmaximum_operations">  Minimum/maximum operations </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/max" title="cpp/algorithm/max"> <span class="t-lines"><span>max</span></span></a></div>
						</div>
					</td>
					<td>   returns the greater of the given values  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_max&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/max" title="cpp/algorithm/ranges/max"> <span class="t-lines"><span>ranges::max</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns the greater of the given values  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_max&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/max_element" title="cpp/algorithm/max element"> <span class="t-lines"><span>max_element</span></span></a></div>
						</div>
					</td>
					<td>   returns the largest element in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_max_element&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/max_element" title="cpp/algorithm/ranges/max element"> <span class="t-lines"><span>ranges::max_element</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns the largest element in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_max_element&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/min" title="cpp/algorithm/min"> <span class="t-lines"><span>min</span></span></a></div>
						</div>
					</td>
					<td>   returns the smaller of the given values  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_min&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/min" title="cpp/algorithm/ranges/min"> <span class="t-lines"><span>ranges::min</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns the smaller of the given values  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_min&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/min_element" title="cpp/algorithm/min element"> <span class="t-lines"><span>min_element</span></span></a></div>
						</div>
					</td>
					<td>   returns the smallest element in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_min_element&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/min_element" title="cpp/algorithm/ranges/min element"> <span class="t-lines"><span>ranges::min_element</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns the smallest element in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_min_element&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/minmax" title="cpp/algorithm/minmax"> <span class="t-lines"><span>minmax</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   returns the smaller and larger of two elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_minmax&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/minmax" title="cpp/algorithm/ranges/minmax"> <span class="t-lines"><span>ranges::minmax</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns the smaller and larger of two elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_minmax&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/minmax_element" title="cpp/algorithm/minmax element"> <span class="t-lines"><span>minmax_element</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   returns the smallest and the largest elements in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_minmax_element&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/minmax_element" title="cpp/algorithm/ranges/minmax element"> <span class="t-lines"><span>ranges::minmax_element</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns the smallest and the largest elements in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_minmax_element&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/clamp" title="cpp/algorithm/clamp"> <span class="t-lines"><span>clamp</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   clamps a value between a pair of boundary values  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_clamp&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/clamp" title="cpp/algorithm/ranges/clamp"> <span class="t-lines"><span>ranges::clamp</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   clamps a value between a pair of boundary values  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_clamp&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Comparison_operations">  Comparison operations </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/equal" title="cpp/algorithm/equal"> <span class="t-lines"><span>equal</span></span></a></div>
						</div>
					</td>
					<td>   determines if two sets of elements are the same  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_equal&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/equal" title="cpp/algorithm/ranges/equal"> <span class="t-lines"><span>ranges::equal</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   determines if two sets of elements are the same  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_equal&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/lexicographical_compare" title="cpp/algorithm/lexicographical compare"> <span class="t-lines"><span>lexicographical_compare</span></span></a></div>
						</div>
					</td>
					<td>   returns true if one range is lexicographically less than another  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_lexicographical_compare&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/lexicographical_compare" title="cpp/algorithm/ranges/lexicographical compare"> <span class="t-lines"><span>ranges::lexicographical_compare</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   returns true if one range is lexicographically less than another  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_lexicographical_compare&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/lexicographical_compare_three_way" title="cpp/algorithm/lexicographical compare three way"> <span class="t-lines"><span>lexicographical_compare_three_way</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   compares two ranges using three-way comparison  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_lexicographical_compare_three_way&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Permutation_operations">  Permutation operations </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/algorithm" title="cpp/header/algorithm">&lt;algorithm&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/is_permutation" title="cpp/algorithm/is permutation"> <span class="t-lines"><span>is_permutation</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   determines if a sequence is a permutation of another sequence  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_is_permutation&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/is_permutation" title="cpp/algorithm/ranges/is permutation"> <span class="t-lines"><span>ranges::is_permutation</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   determines if a sequence is a permutation of another sequence  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_is_permutation&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/next_permutation" title="cpp/algorithm/next permutation"> <span class="t-lines"><span>next_permutation</span></span></a></div>
						</div>
					</td>
					<td>   generates the next greater lexicographic permutation of a range of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_next_permutation&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/next_permutation" title="cpp/algorithm/ranges/next permutation"> <span class="t-lines"><span>ranges::next_permutation</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   generates the next greater lexicographic permutation of a range of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_next_permutation&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/prev_permutation" title="cpp/algorithm/prev permutation"> <span class="t-lines"><span>prev_permutation</span></span></a></div>
						</div>
					</td>
					<td>   generates the next smaller lexicographic permutation of a range of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_prev_permutation&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/prev_permutation" title="cpp/algorithm/ranges/prev permutation"> <span class="t-lines"><span>ranges::prev_permutation</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   generates the next smaller lexicographic permutation of a range of elements  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_prev_permutation&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Numeric_operations">  Numeric operations </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/numeric" title="cpp/header/numeric">&lt;numeric&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/iota" title="cpp/algorithm/iota"> <span class="t-lines"><span>iota</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   fills a range with successive increments of the starting value  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_iota&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/ranges/iota" title="cpp/algorithm/ranges/iota"> <span class="t-lines"><span>ranges::iota</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx23">(C++23)</span></span></span></div>
						</div>
					</td>
					<td>   fills a range with successive increments of the starting value  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/ranges/dsc_iota&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/accumulate" title="cpp/algorithm/accumulate"> <span class="t-lines"><span>accumulate</span></span></a></div>
						</div>
					</td>
					<td>   sums up a range of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_accumulate&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/inner_product" title="cpp/algorithm/inner product"> <span class="t-lines"><span>inner_product</span></span></a></div>
						</div>
					</td>
					<td>   computes the inner product of two ranges of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_inner_product&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/adjacent_difference" title="cpp/algorithm/adjacent difference"> <span class="t-lines"><span>adjacent_difference</span></span></a></div>
						</div>
					</td>
					<td>   computes the differences between adjacent elements in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_adjacent_difference&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/partial_sum" title="cpp/algorithm/partial sum"> <span class="t-lines"><span>partial_sum</span></span></a></div>
						</div>
					</td>
					<td>   computes the partial sum of a range of elements  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_partial_sum&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/reduce" title="cpp/algorithm/reduce"> <span class="t-lines"><span>reduce</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   similar to <span class="t-lc"><a href="/w/cpp/algorithm/accumulate" title="cpp/algorithm/accumulate">std::accumulate</a></span>, except out of order  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_reduce&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/exclusive_scan" title="cpp/algorithm/exclusive scan"> <span class="t-lines"><span>exclusive_scan</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   similar to <span class="t-lc"><a href="/w/cpp/algorithm/partial_sum" title="cpp/algorithm/partial sum">std::partial_sum</a></span>, excludes the ith input element from the ith sum <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_exclusive_scan&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/inclusive_scan" title="cpp/algorithm/inclusive scan"> <span class="t-lines"><span>inclusive_scan</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   similar to <span class="t-lc"><a href="/w/cpp/algorithm/partial_sum" title="cpp/algorithm/partial sum">std::partial_sum</a></span>, includes the ith input element in the ith sum <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_inclusive_scan&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/transform_reduce" title="cpp/algorithm/transform reduce"> <span class="t-lines"><span>transform_reduce</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   applies an invocable, then reduces out of order  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_transform_reduce&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/transform_exclusive_scan" title="cpp/algorithm/transform exclusive scan"> <span class="t-lines"><span>transform_exclusive_scan</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   applies an invocable, then calculates exclusive scan <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_transform_exclusive_scan&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/transform_inclusive_scan" title="cpp/algorithm/transform inclusive scan"> <span class="t-lines"><span>transform_inclusive_scan</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   applies an invocable, then calculates inclusive scan <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_transform_inclusive_scan&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="Operations_on_uninitialized_memory">  Operations on uninitialized memory </span></h5>
					</td>
				</tr>
			</tbody>
		</table>
		<table class="t-dsc-begin">
			<tbody>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/memory" title="cpp/header/memory">&lt;memory&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_copy" title="cpp/memory/uninitialized copy"> <span class="t-lines"><span>uninitialized_copy</span></span></a></div>
						</div>
					</td>
					<td>   copies a range of objects to an uninitialized area of memory <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_copy" title="cpp/memory/ranges/uninitialized copy"> <span class="t-lines"><span>ranges::uninitialized_copy</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies a range of objects to an uninitialized area of memory  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_copy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_copy_n" title="cpp/memory/uninitialized copy n"> <span class="t-lines"><span>uninitialized_copy_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx11">(C++11)</span></span></span></div>
						</div>
					</td>
					<td>   copies a number of objects to an uninitialized area of memory  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_copy_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_copy_n" title="cpp/memory/ranges/uninitialized copy n"> <span class="t-lines"><span>ranges::uninitialized_copy_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies a number of objects to an uninitialized area of memory  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_copy_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_fill" title="cpp/memory/uninitialized fill"> <span class="t-lines"><span>uninitialized_fill</span></span></a></div>
						</div>
					</td>
					<td>   copies an object to an uninitialized area of memory, defined by a range <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_fill&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_fill" title="cpp/memory/ranges/uninitialized fill"> <span class="t-lines"><span>ranges::uninitialized_fill</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies an object to an uninitialized area of memory, defined by a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_fill&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_fill_n" title="cpp/memory/uninitialized fill n"> <span class="t-lines"><span>uninitialized_fill_n</span></span></a></div>
						</div>
					</td>
					<td>   copies an object to an uninitialized area of memory, defined by a start and a count <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_fill_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_fill_n" title="cpp/memory/ranges/uninitialized fill n"> <span class="t-lines"><span>ranges::uninitialized_fill_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   copies an object to an uninitialized area of memory, defined by a start and a count  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_fill_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_move" title="cpp/memory/uninitialized move"> <span class="t-lines"><span>uninitialized_move</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   moves a range of objects to an uninitialized area of memory  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_move&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_move" title="cpp/memory/ranges/uninitialized move"> <span class="t-lines"><span>ranges::uninitialized_move</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   moves a range of objects to an uninitialized area of memory  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_move&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_move_n" title="cpp/memory/uninitialized move n"> <span class="t-lines"><span>uninitialized_move_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   moves a number of objects to an uninitialized area of memory <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_move_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_move_n" title="cpp/memory/ranges/uninitialized move n"> <span class="t-lines"><span>ranges::uninitialized_move_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   moves a number of objects to an uninitialized area of memory  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_move_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_default_construct" title="cpp/memory/uninitialized default construct"> <span class="t-lines"><span>uninitialized_default_construct</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   constructs objects by <a href="/w/cpp/language/default_initialization" title="cpp/language/default initialization">default-initialization</a> in an uninitialized area of memory, defined by a range <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_default_construct&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_default_construct" title="cpp/memory/ranges/uninitialized default construct"> <span class="t-lines"><span>ranges::uninitialized_default_construct</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   constructs objects by <a href="/w/cpp/language/default_initialization" title="cpp/language/default initialization">default-initialization</a> in an uninitialized area of memory, defined by a range <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_default_construct&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_default_construct_n" title="cpp/memory/uninitialized default construct n"> <span class="t-lines"><span>uninitialized_default_construct_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   constructs objects by <a href="/w/cpp/language/default_initialization" title="cpp/language/default initialization">default-initialization</a> in an uninitialized area of memory, defined by a start and a count <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_default_construct_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_default_construct_n" title="cpp/memory/ranges/uninitialized default construct n"> <span class="t-lines"><span>ranges::uninitialized_default_construct_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   constructs objects by <a href="/w/cpp/language/default_initialization" title="cpp/language/default initialization">default-initialization</a> in an uninitialized area of memory, defined by a start and count  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_default_construct_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_value_construct" title="cpp/memory/uninitialized value construct"> <span class="t-lines"><span>uninitialized_value_construct</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   constructs objects by <a href="/w/cpp/language/value_initialization" title="cpp/language/value initialization">value-initialization</a> in an uninitialized area of memory, defined by a range <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_value_construct&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_value_construct" title="cpp/memory/ranges/uninitialized value construct"> <span class="t-lines"><span>ranges::uninitialized_value_construct</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   constructs objects by <a href="/w/cpp/language/value_initialization" title="cpp/language/value initialization">value-initialization</a> in an uninitialized area of memory, defined by a range <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_value_construct&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/uninitialized_value_construct_n" title="cpp/memory/uninitialized value construct n"> <span class="t-lines"><span>uninitialized_value_construct_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   constructs objects by <a href="/w/cpp/language/value_initialization" title="cpp/language/value initialization">value-initialization</a> in an uninitialized area of memory, defined by a start and a count  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_uninitialized_value_construct_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/uninitialized_value_construct_n" title="cpp/memory/ranges/uninitialized value construct n"> <span class="t-lines"><span>ranges::uninitialized_value_construct_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   constructs objects by <a href="/w/cpp/language/value_initialization" title="cpp/language/value initialization">value-initialization</a> in an uninitialized area of memory, defined by a start and a count <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_uninitialized_value_construct_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/destroy" title="cpp/memory/destroy"> <span class="t-lines"><span>destroy</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   destroys a range of objects  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_destroy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/destroy" title="cpp/memory/ranges/destroy"> <span class="t-lines"><span>ranges::destroy</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   destroys a range of objects  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_destroy&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/destroy_n" title="cpp/memory/destroy n"> <span class="t-lines"><span>destroy_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   destroys a number of objects in a range  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_destroy_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/destroy_n" title="cpp/memory/ranges/destroy n"> <span class="t-lines"><span>ranges::destroy_n</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   destroys a number of objects in a range  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_destroy_n&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/destroy_at" title="cpp/memory/destroy at"> <span class="t-lines"><span>destroy_at</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx17">(C++17)</span></span></span></div>
						</div>
					</td>
					<td>   destroys an object at a given address  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_destroy_at&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/destroy_at" title="cpp/memory/ranges/destroy at"> <span class="t-lines"><span>ranges::destroy_at</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   destroys an object at a given address  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_destroy_at&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/construct_at" title="cpp/memory/construct at"> <span class="t-lines"><span>construct_at</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   creates an object at a given address  <br> <span class="t-mark">(function template)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/dsc_construct_at&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/memory/ranges/construct_at" title="cpp/memory/ranges/construct at"> <span class="t-lines"><span>ranges::construct_at</span></span></a></div>
							<div><span class="t-lines"><span><span class="t-mark-rev t-since-cxx20">(C++20)</span></span></span></div>
						</div>
					</td>
					<td>   creates an object at a given address  <br> <span class="t-mark">(niebloid)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/memory/ranges/dsc_construct_at&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr>
					<td colspan="2">
						<h5> <span class="mw-headline" id="C_library">  C library </span></h5>
					</td>
				</tr>
				<tr class="t-dsc-header">
					<td colspan="2">
						<div>Defined in header <code><a href="/w/cpp/header/cstdlib" title="cpp/header/cstdlib">&lt;cstdlib&gt;</a></code> </div>
					</td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/qsort" title="cpp/algorithm/qsort"> <span class="t-lines"><span>qsort</span></span></a></div>
						</div>
					</td>
					<td>   sorts a range of elements with unspecified type <br> <span class="t-mark">(function)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_qsort&amp;action=edit">[edit]</a></span></td>
				</tr>
				<tr class="t-dsc">
					<td>
						<div class="t-dsc-member-div">
							<div><a href="/w/cpp/algorithm/bsearch" title="cpp/algorithm/bsearch"> <span class="t-lines"><span>bsearch</span></span></a></div>
						</div>
					</td>
					<td>   searches an array for an element of unspecified type <br> <span class="t-mark">(function)</span> <span class="editsection noprint plainlinks" title="Edit this template"><a rel="nofollow" class="external text" href="https://en.cppreference.com/mwiki/index.php?title=Template:cpp/algorithm/dsc_bsearch&amp;action=edit">[edit]</a></span></td>
				</tr>
			</tbody>
		</table>
	</body>
</html>